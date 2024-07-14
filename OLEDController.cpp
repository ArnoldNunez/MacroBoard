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