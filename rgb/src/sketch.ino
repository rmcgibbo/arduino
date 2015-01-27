#include "colorspace.hpp"

const int button1_pin = 2;
const int button2_pin = 3;
const int led_pin = 13;
const int rgb_pins[] = {11, 10, 9};

float hsl[3] = {120.0, 1.0, 0.2};
byte rgb[3];
// long last_press_time = 0;
// long debounce = 200;
// bool prev_button1 = HIGH;
// bool prev_button2 = HIGH;

void setup() {
    Serial.begin(9600);
    hsl_to_rgb(hsl[0], hsl[1], hsl[2], rgb[0], rgb[1], rgb[2]);
    pinMode(button1_pin, INPUT_PULLUP);
    pinMode(button2_pin, INPUT_PULLUP);
    pinMode(led_pin, OUTPUT);
    for (int i = 0; i < 3; i++)
        pinMode(rgb_pins[i], OUTPUT);
}

void loop() {
    // bool button1 = digitalRead(button1_pin);
    // bool button2 = digitalRead(button2_pin);
    // bool pressed1 = (button1 == HIGH && prev_button1 == LOW);
    // bool pressed2 = (button2 == HIGH && prev_button2 == LOW);
    // if ((pressed1 || pressed2) && (millis() - last_press_time) > debounce) {
    //     hsl[2] += 0.1 * (pressed1 ? 1 : -1);
    //     hsl[2] = fmod(hsl[2], 1.0);
    //     hsl_to_rgb(hsl[0], hsl[1], hsl[2], rgb[0], rgb[1], rgb[2]);
    //
    //     for (int i = 0; i < 3; i++) {
    //         Serial.print(hsl[0], 5);
    //         Serial.print(" ");
    //     }
    //     Serial.println("");
    //     last_press_time = millis();
    // }
    //
    // prev_button1 = button1;
    // prev_button2 = button2;

    if (Serial.available() > 0) {
        // Each message is initialized with a newline, and then contains
        // 3 bytes.
        byte firstByte = Serial.read();
        if (firstByte == '\n') {
            for (int i = 0; i < 3; i++) {
                while (Serial.available() <= 0) {
                    delay(10);
                }
                rgb[i] = Serial.read();
            }
        } else{
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        analogWrite(rgb_pins[i], rgb[i]);
    }


}
