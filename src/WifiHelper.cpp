#include "WiFiHelper.h"

// Definisi konstanta
const unsigned long CONNECTION_TIMEOUT = 15000; // Timeout untuk koneksi WiFi
const long SIGNAL_THRESHOLD = -80;              // Threshold RSSI untuk kualitas sinyal

unsigned long previousMillis = 0;
const long CHECK_INTERVAL = 10000; // Interval pengecekan dalam milidetik

// Definisi fungsi untuk memeriksa kekuatan sinyal WiFi
void checkSignalStrength()
{
    long rssi = WiFi.RSSI();
    Serial.print("Kekuatan sinyal: ");
    Serial.print(rssi);
    Serial.println(" dBm");
    if (rssi < SIGNAL_THRESHOLD)
    {
        Serial.println("Kualitas sinyal buruk. Pertimbangkan untuk mencari sinyal yang lebih kuat.");
    }
}

// Definisi fungsi untuk memeriksa status koneksi WiFi
bool wifiConnected()
{
    return (WiFi.status() == WL_CONNECTED) ? true : false;
}

// Definisi fungsi untuk mencoba menghubungkan ke WiFi
bool attemptWiFiConnection(const char *ssid, const char *password, unsigned long timeout)
{
    unsigned long startAttemptTime = millis();
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (!wifiConnected() && (millis() - startAttemptTime < timeout))
    {
        delay(1000);
        Serial.print(".");
    }

    if (wifiConnected())
    {
        Serial.println("\nWiFi terhubung!");
        Serial.print("Alamat IP: ");
        Serial.println(WiFi.localIP());
        return true;
    }
    else
    {
        Serial.println("\nGagal terhubung ke WiFi setelah timeout.");
        return false;
    }
}

// Definisi fungsi untuk menghubungkan ke jaringan WiFi yang tersedia
void connectToWiFi()
{
    Serial.println("Menghubungkan ke WiFi...");

    // Iterasi melalui array sampai menemukan nullptr
    for (int i = 0; ssids[i] != nullptr && passwords[i] != nullptr; i++)
    {
        Serial.print("Mencoba ");
        Serial.println(ssids[i]);
        if (attemptWiFiConnection(ssids[i], passwords[i]))
        {
            return; // Jika terhubung, keluar dari fungsi
        }
    }

    Serial.println("\nGagal terhubung ke WiFi setelah mencoba semua jaringan.");
}

// Definisi fungsi untuk memeriksa dan menyambung kembali ke WiFi jika terputus
void reconnectWiFi()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= CHECK_INTERVAL)
    {
        previousMillis = currentMillis;

        if (!wifiConnected())
        {
            Serial.println("Koneksi WiFi terputus! Mencoba menghubungkan kembali...");
            connectToWiFi();
        }
        else
        {
            checkSignalStrength();
        }
    }
}
