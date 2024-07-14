/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#ifndef KEYPAD_CONTROLLER_H
#define KEYPAD_CONTROLLER_H

#include "KeySwitch.h"

#include <Adafruit_NeoPixel.h>
#include <vector>

/**
 * Class representing the main application processing.
 */
class KeypadController
{
public:
  /**
   * Constructor
   * \param 
   */
  KeypadController();

  /**
   * Destructor
   */
  ~KeypadController();

  /**
   * Copy constructor (disabled)
   */
  KeypadController(const KeypadController&) = delete;

  /**
   * Play the given frequency for a given duration.
   * \param frequency The tone frequency in Hz
   * \param duration  The duration of the tone in milliseconds
  */
  // void playTone(unsigned short frequency, unsigned long duration);
  void initializeLEDs();

private:
  // The list of keys available.
  std::vector<KeySwitch> mKeyMatrix;

  // The LED matrix
  Adafruit_NeoPixel mPixelMatrix;
};

 #endif // KEYPAD_CONTROLLER_H