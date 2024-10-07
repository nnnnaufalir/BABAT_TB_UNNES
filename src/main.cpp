// Global Header
#include <Arduino.h>
#include <BabattbTimer.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Local Header
#include "Babat_Config.h"
#include "Babat_Loadcell.h"
#include "Babat_OTA.h"
#include "Babat_Indicator.h"
#include "Babat_Display.h"
#include "WiFiHelper.h"

// User Credentials
#define USER_EMAIL "agussupri710@gmail.com"
#define USER_PASSWORD "aguss710"

// URL Definitions
#define BASE_URL "https://babattb.cloud/api"
#define LOGIN_URL BASE_URL "/login"
#define LOGOUT_URL BASE_URL "/logout"
#define PASIEN_URL BASE_URL "/pasien"
#define JADWAL_MINUM_URL BASE_URL "/jadwal"
#define JADWAL_KONTROL_URL BASE_URL "kontrol"
#define DATA_OBAT_URL BASE_URL "/logminumobat"

//---------Timer Class-------------//
BabattbTimer timer;

//-------Function---------------//
void printData();
void loadcell_loop();
void login();
void postDataObat(int skor);

//---------Global Variables-----------//
//--------Obat---------//
int jumlah_obat;
int jumlah_saat_ini;

// Global Variables
String token;
String currentSSID;
String currentEmail;

void setup()
{
  // SERIAL 0
  Serial.begin(SERIAL_BAUDRATE);

  // Display
  display_setup();

  // Buzzer
  Start_bootingBuzz();

  display_booting();

  // WIFI
  connectToWiFi();

  // login
  login();

  // OTA
  OTA_setup();

  delay(1000);

  loadcell_setup();
  End_bootingBuzz();
  display_clear();

  //------Timer running------------//
  timer.setInterval(20, loadcell_loop);

  /*
  //-------Debug Print-------------//
  timer.setInterval(500, printData);
  */
}

void loop()
{
  String hari = "Rab";
  byte tanggal = 9;
  byte bulan = 10;
  display_main(jumlah_obat, 1, 7, 30, 27, 9, 2024, hari, tanggal, bulan);

  if (jumlah_saat_ini != jumlah_obat)
  {
    int data_post = jumlah_saat_ini - jumlah_obat;
    if (data_post < 0)
    {
      data_post = 0;
    }

    else
    {
      postDataObat(data_post);
    }
    jumlah_saat_ini = jumlah_obat;
  }

  reconnectWiFi();
  OTA_loop();
  // printData();

  timer.run();
}

//-------Running counting drug----------//
void loadcell_loop()
{
  jumlah_obat = estimatedCount();
}

//-------Debug Print------------//
void printData()
{
  Serial.print(rawWeight());
  Serial.print(" | ");
  Serial.print(processedWeight());
  Serial.print(" | ");
  Serial.print(jumlah_obat);
  Serial.println("");
}

void login()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(LOGIN_URL);                                               // Use defined login URL
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Set content type to form-data

    // Prepare form-data request body
    String requestBody = "email=" + String(USER_EMAIL) + "&password=" + String(USER_PASSWORD);

    int httpResponseCode = http.POST(requestBody);

    Serial.println("Login Response Code: " + String(httpResponseCode));

    if (httpResponseCode == 200)
    { // Check if the response code is 200 OK
      String response = http.getString();
      Serial.println("Response: ");

      DynamicJsonDocument doc(2048); // Increase size if needed to accommodate your JSON structure
      DeserializationError error = deserializeJson(doc, response);

      if (!error)
      {
        // Print the JSON in a pretty format
        serializeJsonPretty(doc, Serial);

        token = doc["data"][0]["token"].as<String>();

        Serial.println("\nBearer Token: " + token);
        currentEmail = USER_EMAIL; // Save the logged-in email
        Serial.println("Logged in as: " + currentEmail);
      }
      else
      {
        Serial.println("Failed to parse JSON: " + String(error.c_str()));
      }
    }
    else
    {
      Serial.println("Error on HTTP request: " + String(httpResponseCode));
    }

    http.end();
  }
  else
  {
    Serial.println("WiFi not connected");
  }
}

void postDataObat(int skor)
{
  if (WiFi.status() == WL_CONNECTED && !token.isEmpty())
  {
    HTTPClient http;
    http.begin(DATA_OBAT_URL);                                           // URL untuk post data
    http.addHeader("Authorization", "Bearer " + token);                  // Sertakan Bearer token di header
    http.addHeader("Accept", "application/json");                        // Set header Accept untuk menerima JSON
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Content type form-data

    // Siapkan form-data untuk request body
    String requestBody = "skor=" + String(skor);

    // Kirim POST request
    int httpResponseCode = http.POST(requestBody);

    // Cek hasil response
    Serial.println("POST Response Code: " + String(httpResponseCode));

    if (httpResponseCode == 200 || httpResponseCode == 201)
    { // Tangani status 200 dan 201
      String response = http.getString();
      Serial.println("Response: " + response);

      // Jika perlu, parse response JSON
      DynamicJsonDocument doc(2048); // Sesuaikan ukuran buffer jika perlu
      DeserializationError error = deserializeJson(doc, response);

      if (!error)
      {
        Serial.println("Formatted JSON Response:");
        serializeJsonPretty(doc, Serial); // Cetak response JSON dalam format yang lebih mudah dibaca
      }
      else
      {
        Serial.println("Failed to parse JSON: " + String(error.c_str()));
      }
    }
    else
    {
      Serial.println("Error on HTTP request: " + String(httpResponseCode));
    }

    http.end(); // Menutup koneksi HTTP
  }
  else
  {
    Serial.println("WiFi tidak terhubung atau token tidak tersedia");
  }
}
