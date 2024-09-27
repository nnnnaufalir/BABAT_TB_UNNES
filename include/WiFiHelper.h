#ifndef WIFIHELPER_H
#define WIFIHELPER_H

#include <WiFi.h>
#include "Babat_Config.h"

// Deklarasi konstanta
extern const unsigned long CONNECTION_TIMEOUT;
extern const long SIGNAL_THRESHOLD;
extern unsigned long previousMillis;
extern const long CHECK_INTERVAL;

// Deklarasi fungsi
void checkSignalStrength();
bool wifiConnected();
bool attemptWiFiConnection(const char *ssid, const char *password, unsigned long timeout = CONNECTION_TIMEOUT);
void connectToWiFi();
void reconnectWiFi();

#endif // WIFIHELPER_H
