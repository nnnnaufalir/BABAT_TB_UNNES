#ifndef BABAT_LOADCELL_H
#define BABAT_LOADCELL_H

#include <HX711.h>
#include "Babat_Config.h"

// Konstanta
#define FACTOR 5925
#define BUFFER_SIZE 10
#define OBAT_WEIGHT 1.55

// Deklarasi variabel global
extern HX711 scale;
extern float buffer[BUFFER_SIZE];
extern int bufferIndex;

// Deklarasi fungsi
void initializeBuffer();
void tare();
float rawWeight();
void rawBuffer();
float calculateAverage();
float estimatedCount();
void loadcell_setup();

#endif // BABAT_LOADCELL_H
