#ifndef BABAT_CONFIG_H
#define BABAT_CONFIG_H

// SERIAL BAUDRATE
#define SERIAL_BAUDRATE 115200

// WiFi Credentials
extern const char *ssids[];
extern const char *passwords[];

// LOADCELL PIN
#define LOADCELL_DOUT_PIN 13
#define LOADCELL_SCK_PIN 14

// BUZZER PIN
#define PIN_BUZZER 32

#define TFT_CS 5
#define TFT_RST 12
#define TFT_DC 15

#endif // CONFIG_H
