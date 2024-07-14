/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #include "KeypadController.h"
 
 #include <Wire.h>

//-----
KeypadController::KeypadController() 
   : mNumSwitches(12),
     mKeyMatrix(),
     mPixelMatrix(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800)
{
   // Supporting 12 keys - GPIO 1 - 12
   for (unsigned short i = 0; i <= mNumSwitches; ++i)
   {
      // Set keyswitches to
      mKeyMatrix.push_back(new KeySwitch(i));
      mKeyMatrix[i]->enableInput();
   }
}

//-----
KeypadController::~KeypadController()
{
   for (unsigned short i = 0; i < mKeyMatrix.size(); ++i)
   {
      delete mKeyMatrix[i];
   }
}

//-----
void KeypadController::initializeLEDs()
{
   mPixelMatrix.begin();
   mPixelMatrix.setBrightness(255);
   mPixelMatrix.show();
}

//-----
void KeypadController::process()
{
   for (const auto& key : mKeyMatrix)
   {
      if (key->isPressed())
      {
         
      }
   }
}

//-----
std::vector<KeySwitch*> KeypadController::getState() const
{
   return mKeyMatrix;
}
