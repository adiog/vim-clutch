#include "Arduino.h"
#include "HID.h"
#include "Keyboard.h"


void setup()
{
    pinMode(13, OUTPUT);
    pinMode(3, INPUT_PULLUP);
//    digitalWrite(2, HIGH);
    Keyboard.begin();
    Serial.begin(9600);
}

int previousButtonState = 0;
int buttonPin = 3;


void loop()
{
    int buttonState = digitalRead(buttonPin) != 0;

    if (buttonState != previousButtonState)
    {
        //Serial.println(millis());
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
