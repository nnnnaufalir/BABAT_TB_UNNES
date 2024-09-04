#ifndef CONFIG_H
#define CONFIG_H

// SERIAL BAUDRATE
#define SERIAL_BAUDRATE 115200

// WiFi Credentials
const char *ssids[] = {"Galaxy A50s", "SSID2", "SSID3", nullptr};
const char *passwords[] = {"22224444", "password2", "password3", nullptr};

// LOADCELL PIN
#define LOADCELL_DOUT_PIN 5
#define LOADCELL_SCK_PIN 18

// BUZZER PIN
#define PIN_BUZZER 19

#endif // CONFIG_H
