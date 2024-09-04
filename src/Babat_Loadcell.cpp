#include "Babat_Loadcell.h"

// Inisialisasi variabel global
HX711 scale;
float buffer[BUFFER_SIZE];
int bufferIndex = 0;

// Setup buffer
void initializeBuffer()
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = 0.0f;
    }
}

// Set to 0
void tare()
{
    scale.set_scale(FACTOR);
    scale.tare();
}

// Baca berat
float rawWeight()
{
    return scale.get_units();
}

// Append buffer
void rawBuffer()
{
    buffer[bufferIndex] = rawWeight();
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
}

// Hitung rata-rata
float calculateAverage()
{
    float sum = 0.0f;
    rawBuffer();
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        sum += buffer[i];
    }
    return sum / BUFFER_SIZE;
}

// Hasil perhitungan obat
float estimatedCount()
{
    return calculateAverage() / OBAT_WEIGHT;
}

// Setup loadcell
void loadcell_setup()
{
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    tare();
    initializeBuffer();
}
