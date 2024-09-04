// Global Header
#include <Arduino.h>
#include <BabattbTimer.h>

// Local Header
#include "Babat_Config.h"
#include "Babat_Loadcell.h"
#include "Babat_OTA.h"
#include "Babat_Indicator.h"
#include "WiFiHelper.h"

//---------Timer Class-------------//
BabattbTimer timer;

//-------Function---------------//
void printData();
void loadcell_loop();

//---------Global Variables-----------//
//--------Obat---------//
int jumlah_obat;

void setup()
{
  // SERIAL 0
  Serial.begin(SERIAL_BAUDRATE);

  // Buzzer
  buzzer_setup();
  Start_bootingBuzz();

  // WIFI
  connectToWiFi(ssids, passwords);

  // OTA
  OTA_setup();

  delay(2000);

  loadcell_setup();
  End_bootingBuzz();

  //------Timer running------------//
  timer.setInterval(20, loadcell_loop);

  /*
  //-------Debug Print-------------//
  timer.setInterval(500, printData);
  */
}

void loop()
{

  reconnectWiFi(ssids, passwords);
  OTA_loop();

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
