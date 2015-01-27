#include <LCDKeypad.h>

LCDKeypad lcd;
int lcd_key;


void setup() {
     lcd.begin(16, 2);
     lcd.backlightOn();
     lcd.setCursor(0,0);
     lcd.print("Push the buttons");
}


void loop() {
    lcd.setCursor(9,1);
    lcd.print(millis()/1000);

    lcd.setCursor(0,1);
    lcd_key = lcd.button();

    if (lcd_key == LCDKeypad::Right) {
     lcd.print("RIGHT ");
    } else if (lcd_key == LCDKeypad::Left) {
     lcd.print("LEFT ");
    }
}
