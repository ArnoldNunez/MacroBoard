/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #ifndef KEY_SWITCH_H
 #define KEY_SWITCH_H

 #include "Context.h"
 #include "OLEDController.h"

/**
 * Class representing the main application processing.
 */
class KeySwitch
{
public:
  /**
   * Constructor
   * \param pin Pin associated with the keyswitch
   */
  KeySwitch(unsigned short pin);

  /**
   * Destructor
   */
  ~KeySwitch();

  /**
   * Copy constructor (disabled)
   */
  KeySwitch(const KeySwitch&) = delete;

  /**
   * Enable switch input, INPUT_PULLUP mode.
   */
  void enableInput();

  /**
   * Check is switch is pressed
   * \return True is pressed, false otherwise
   */
  bool isPressed() const;

  /**
   * Gets numerical id for the keyswitch
   */
  unsigned short getId() const;

private:
  // Id associated with the keyswitch
  unsigned short mId;

  // Pin associated with the keyswitch
  unsigned short mPin;
};

 #endif // KEY_SWITCH_H