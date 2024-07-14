/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #include "KeypadController.h"
 
 #include <Wire.h>

//-----
KeypadController::KeypadController() 
   : mKeyMatrix(),
     mPixelMatrix(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800)
{
}

//-----
KeypadController::~KeypadController()
{
}

//-----
void KeypadController::initializeLEDs()
{
   mPixelMatrix.begin();
   mPixelMatrix.setBrightness(255);
   mPixelMatrix.show();
}
