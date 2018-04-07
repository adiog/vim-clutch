#include "Arduino.h"
#include "HID.h"
#include "Keyboard.h"

#ifndef I_AM_USING_QWERTY
  #define ENTER_INSERT_MODE_KEY ('g')
  #define MOVE_CURSOR_RIGHT_KEY (';')
#else
  #define ENTER_INSERT_MODE_KEY ('i')
  #define MOVE_CURSOR_RIGHT_KEY ('l')
#endif


const int CLUTCH_PIN = 2;
int previousButtonState = 0;


void setup()
{
    pinMode(CLUTCH_PIN, INPUT_PULLUP);
    Keyboard.begin();
    Serial.begin(9600);
    while(!Serial) {}
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
            Keyboard.write(ENTER_INSERT_MODE_KEY);
        }
        else
        {
            Serial.println("released");
            Keyboard.write(KEY_ESC);
            Keyboard.write(MOVE_CURSOR_RIGHT_KEY);
        }
    }

    previousButtonState = buttonState;
    delay(5);
}
