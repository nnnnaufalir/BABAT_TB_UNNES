// Global Header
#include <Arduino.h>
#include <BabattbTimer.h>

// Local Header
#include "Babat_Config.h"
#include "Babat_Loadcell.h"
#include "Babat_OTA.h"
#include "Babat_Indicator.h"
#include "Babat_Display.h"
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

  // Display
  display_setup();

  // Buzzer
  buzzer_setup();
  Start_bootingBuzz();

  display_booting();

  // WIFI
  // connectToWiFi();

  // OTA
  // OTA_setup();

  // delay(2000);

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
  blipBuzz(200);
  // display_main();
  // reconnectWiFi();
  // OTA_loop();
  printData();

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
