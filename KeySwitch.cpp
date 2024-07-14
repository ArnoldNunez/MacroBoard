/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #include "KeySwitch.h"
 
 #include <Wire.h>

//-----
KeySwitch::KeySwitch(unsigned short pin) 
: mId(pin),
  mPin(pin)
{
}

//-----
KeySwitch::~KeySwitch()
{
}

//-----
void KeySwitch::enableInput()
{
    pinMode(mPin, INPUT_PULLUP);
}

//-----
bool KeySwitch::isPressed() const
{
    // Since we are input pullup mode, the switch is HIGH
    // when not pressed and LOW when pressed. therefore we
    // negate the output of digitalRead()
    return !digitalRead(mPin);
}

//-----
unsigned short KeySwitch::getId() const
{
    return mId;
}