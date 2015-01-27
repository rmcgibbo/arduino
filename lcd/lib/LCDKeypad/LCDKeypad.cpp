/*
  LCDKeypad.cpp
*/
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "LCDKeypad.h"

LCDKeypad::LCDKeypad() : LiquidCrystal(8, 9, 4, 5, 6, 7)
{
    backlightOn();
}

LCDKeypad::Button LCDKeypad::button() {
    // read the buttons

    // read the value from the sensor
    int adc_key_in = analogRead(0);
    // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close

    // We make this the 1st option for speed reasons since it will
    // be the most likely result
    if (adc_key_in > 1000) return LCDKeypad::None;
    if (adc_key_in < 50)   return LCDKeypad::Right;
    if (adc_key_in < 195)  return LCDKeypad::Up;
    if (adc_key_in < 380)  return LCDKeypad::Down;
    if (adc_key_in < 555)  return LCDKeypad::Left;
    if (adc_key_in < 790)  return LCDKeypad::Select;
    return LCDKeypad::None;  // when all others fail, return this...
}

void LCDKeypad::backlightOn() {
    pinMode(10, INPUT);
}

void LCDKeypad::backlightOff() {
    pinMode(10, OUTPUT);
}
