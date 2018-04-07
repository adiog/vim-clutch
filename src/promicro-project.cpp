#include "Arduino.h"
#include "HID.h"
#include "Keyboard.h"

int previousButtonState = 0;
int CLUTCH_PIN = 3;


void setup()
{
    pinMode(CLUTCH_PIN, INPUT_PULLUP);
    Keyboard.begin();
    Serial.begin(9600);
}


void loop()
{
    int buttonState = digitalRead(CLUTCH_PIN) != 0;

    if (buttonState != previousButtonState)
    {
        if (buttonState)
        {
            Serial.println("pressed");
            Keyboard.write(KEY_ESC);
            Keyboard.write('g');
        }
        else
        {
            Serial.println("released");
            Keyboard.write(KEY_ESC);
            Keyboard.write(';');
        }
    }

    previousButtonState = buttonState;
    delay(5);
}
