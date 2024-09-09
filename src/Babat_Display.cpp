#include "Babat_Display.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

void display_clear()
{
    lcd.clear();
}

void display_setup()
{
    lcd.init();
    lcd.backlight();
}

void display_booting()
{
    lcd.setCursor(3, 0);
    lcd.print("Selamat Datang");
    lcd.setCursor(4, 1);
    lcd.print("BABAT TB-Box");
    lcd.setCursor(5, 2);
    lcd.print("UNNES 2024");
    lcd.setCursor(5, 3);
    lcd.print("v 24.09.04");
}

void display_main()
{
    lcd.setCursor(0, 0);
    lcd.print("Sen");
    lcd.print("-");
    lcd.print("02");
    lcd.print("/");
    lcd.print("09");
    lcd.print(" ");
    lcd.setCursor(10, 0);
    lcd.print("17");
    lcd.print(":");
    lcd.print("20");

    lcd.print(" ");
    lcd.print("59");
    lcd.print("%   ");

    lcd.setCursor(0, 1);
    lcd.print("Dosis Obat  : ");
    lcd.print("3");
    lcd.print("   ");
    lcd.setCursor(0, 2);
    lcd.print("Sisa Obat   : ");
    lcd.print("33");
    lcd.print("    ");
    lcd.setCursor(0, 3);
    lcd.print("11 Hari lagi!           ");
}

void display_trial()
{
    lcd.setCursor(0, 0);
    lcd.print("   Login Berhasil! ");
    lcd.setCursor(6, 2);
    lcd.print(" Pasien");
    lcd.setCursor(7, 3);
    lcd.print(" Budi");
}
