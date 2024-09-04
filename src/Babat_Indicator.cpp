#include <Arduino.h>
#include "Babat_Config.h"
#include "Babat_Indicator.h"

void buzzer_setup()
{
    pinMode(PIN_BUZZER, OUTPUT);
}

void blipBuzz(int x)
{
    digitalWrite(PIN_BUZZER, HIGH);
    delay(x);
    digitalWrite(PIN_BUZZER, LOW);
}

void Start_bootingBuzz()
{
    blipBuzz(50);
}

void End_bootingBuzz()
{
    blipBuzz(250);
}