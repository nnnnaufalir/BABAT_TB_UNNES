#ifndef BABAT_OTA_H
#define BABAT_OTA_H

#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// Deklarasi fungsi untuk setup OTA
void OTA_setup();

// Deklarasi fungsi untuk loop OTA
void OTA_loop();

#endif // BABAT_OTA_H
