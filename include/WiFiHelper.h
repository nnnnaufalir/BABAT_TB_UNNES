#ifndef WIFIHELPER_H
#define WIFIHELPER_H

#include <WiFi.h>

// Deklarasi konstanta
extern const unsigned long CONNECTION_TIMEOUT;
extern const long SIGNAL_THRESHOLD;
extern unsigned long previousMillis;
extern const long CHECK_INTERVAL;

// Deklarasi fungsi
void checkSignalStrength();
bool wifiConnected();
bool attemptWiFiConnection(const char *ssid, const char *password, unsigned long timeout = CONNECTION_TIMEOUT);
void connectToWiFi(const char *ssids[], const char *passwords[]);
void reconnectWiFi(const char *ssids[], const char *passwords[]);

#endif // WIFIHELPER_H
