#ifndef BABAT_DISPLAY_H
#define BABAT_DISPLAY_H

#include <LiquidCrystal_I2C.h>
#include "Babat_Config.h"

void display_clear();
void display_setup();
void display_main();
void display_booting();
void display_trial();

#endif