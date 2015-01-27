/**
 * LCDKeypad.h
 */
#ifndef LCDKeypad_h
#define LCDKeypad_h
#include <LiquidCrystal.h>


class LCDKeypad: public LiquidCrystal
{
  public:

    enum Button {
      None = -1,
      Right = 0,
      Up = 1,
      Down = 2,
      Left = 3,
      Select = 4
    };

    LCDKeypad();

    /**
     * Get the current button state
     */
    Button button();

    /**
     * Safely set the LCD backlight ON
     * (See http://forum.arduino.cc//index.php?topic=96747)
     */
    void backlightOn();

    /**
     * Safely set the LCD backlight OFF
     * (See http://forum.arduino.cc//index.php?topic=96747)
     */
    void backlightOff();
};

#endif

