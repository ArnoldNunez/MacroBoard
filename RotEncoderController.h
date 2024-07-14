/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #ifndef ROT_ENCODER_H
 #define ROT_ENCODER_H

 #include "Context.h"
 #include "OLEDController.h"

 #include <RotaryEncoder.h>

 #include <memory>

/**
 * Class representing the main application processing.
 */
class RotEncoderController
{
public:
  /**
   * Constructor
   */
  RotEncoderController(unsigned short pin1, unsigned short pin2);

  /**
   * Destructor
   */
  ~RotEncoderController();

  /**
   * Copy constructor (disabled)
   */
  RotEncoderController(const RotEncoderController&) = delete;

private:
  // Pin 1 associated with the rotaty encoder.
  unsigned short mPin1;

  // Pin 2 associated with the rotary encoder.
  unsigned short mPin2;

  // The underlying hardware rotary encoder
  std::unique_ptr<RotaryEncoder> mEncoder;
};

 #endif // ROT_ENCODER_H