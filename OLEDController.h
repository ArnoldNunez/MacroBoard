/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#ifndef OLED_CONTROLLER_H
#define OLED_CONTROLLER_H

#include <Adafruit_SH110X.h>
#include <vector>

#include "KeySwitch.h"

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

  /**
   * Sets up the OLED display
   */
  void setup();

  /**
   * The OLED render loop 
   */
  void render();

  /**
   * Draw the keypad state onto the OLED
   */
  // void drawKeypadState(const std::vector<KeySwitch*> state);

private:
   // The display instance
   Adafruit_SH1106G mDisplay;
};

#endif // OLED_CONTROLLER_H