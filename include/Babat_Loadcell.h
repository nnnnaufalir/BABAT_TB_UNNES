#ifndef BABAT_LOADCELL_H
#define BABAT_LOADCELL_H

#include <HX711.h>
#include <SimpleKalmanFilter.h>
#include "Babat_Config.h"

// Konstanta
#define FACTOR 5925
#define BUFFER_SIZE 15
#define OBAT_WEIGHT 1.55

// Deklarasi fungsi
void initializeBuffer();
void tare();
float rawWeight();
void rawBuffer();
float processedWeight();
float estimatedCount();
void loadcell_setup();
float processedWeight_KF();
float estimatedCount_KF();

#endif // BABAT_LOADCELL_H
