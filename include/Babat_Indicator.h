#ifndef BABAT_INDICATOR_H
#define BABAT_INDICATOR_H

#include <Arduino.h>
#include "Babat_Config.h"

void buzzer_setup();
void blipBuzz(int x);
void Start_bootingBuzz();
void End_bootingBuzz();

#endif