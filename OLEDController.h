/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#ifndef OLED_CONTROLLER_H
#define OLED_CONTROLLER_H

#include <Adafruit_SH110X.h>

/**
 * Class used to control the macropad OLED controller.
 */
class OLEDController
{
public:
  /**
   * Constructor
   */
  OLEDController(unsigned short pixelWidth, unsigned short pixelHeight);

  /**
   * Destructor
   */
  ~OLEDController();

  /**
   * Copy constructor (disabled)
   */
  OLEDController(const OLEDController&) = delete;

private:
   // The display instance
   Adafruit_SH1106G mDisplay;
};

#endif // OLED_CONTROLLER_H