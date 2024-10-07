#include "Babat_Indicator.h"

void buzzer_setup()
{
    pinMode(PIN_BUZZER, OUTPUT);
}

void blipBuzz(int x)
{
    pinMode(PIN_BUZZER, OUTPUT);
    digitalWrite(PIN_BUZZER, LOW);
    delay(x);
    digitalWrite(PIN_BUZZER, HIGH);
    pinMode(PIN_BUZZER, INPUT);
}

void Start_bootingBuzz()
{
    blipBuzz(50);
}

void End_bootingBuzz()
{
    blipBuzz(250);
}