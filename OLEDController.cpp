/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#include "OLEDController.h"

//-----
OLEDController::OLEDController(unsigned short pixelWidth, unsigned short pixelHeight)
   : mDisplay(pixelWidth, pixelHeight, &SPI1, OLED_DC, OLED_RST, OLED_CS)
{
   // We don't use the i2c address but we will reset
   mDisplay.begin(0, true);
   mDisplay.display();
}

//-----
OLEDController::~OLEDController()
{
}

//-----
void OLEDController::setup()
{
   mDisplay.setTextSize(1);
   mDisplay.setTextWrap(false);
   // White text, black background
   mDisplay.setTextColor(SH110X_WHITE, SH110X_BLACK);
}

//-----
void OLEDController::render(const std::vector<KeySwitch*>& state)
{
   mDisplay.setTextColor(SH110X_WHITE, SH110X_BLACK);
   mDisplay.clearDisplay();
   mDisplay.setCursor(0, 0);
   mDisplay.println("* Adafruit Macropad *");

   drawKeypadState(state);

   mDisplay.display();
}

//-----
void OLEDController::drawKeypadState(const std::vector<KeySwitch*> state)
{
   for (const auto& switchState : state)
   {
      if (switchState->isPressed())
      {
         mDisplay.setTextColor(SH110X_BLACK, SH110X_WHITE);
      }
      else
      {
         mDisplay.setTextColor(SH110X_WHITE, SH110X_BLACK);
      }

      unsigned short i = switchState->getId();
      mDisplay.setCursor(((i-1) % 3)*48, 32 + ((i-1)/3)*8);
      mDisplay.print("KEY");
      mDisplay.print(i);
   }
}
