#ifndef BABAT_DISPLAY_H
#define BABAT_DISPLAY_H

#include "Babat_Config.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

void display_clear();
void display_setup();
void display_main(int sisa_obat, byte id_box, byte jam_minum, byte mnt_minum, byte tglKontrol, byte bln_kontrol, int thnKontrol, String tgl, byte har, byte bul);
void display_booting();
void date(String valDay, byte valDate, byte valMonth, int valYear);
void time(byte valHour, byte valMinute);
void notifKontrol(byte valueControlDate, String valueControlMonth, int valueControlYear);

#endif