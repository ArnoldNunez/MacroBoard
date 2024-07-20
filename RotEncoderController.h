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

  /**
   * main processing loop for Encoder. Should be called periodically
   * to process rotary encoder state.
   */
  void process();

  /**
   * Getter for the current encoder position
   * \return  The current encoder position
   */
  int getPosition();

  /**
   * Getter for the encoder direction
   * \return  The encoder direction
   */
  int getDirection();

private:
  // Pin 1 associated with the rotaty encoder.
  unsigned short mPin1;

  // Pin 2 associated with the rotary encoder.
  unsigned short mPin2;

  // Tracks the new position of the encoder.
  int mNewPos;

  // Track the previous position of the encoder.
  int mOldPos;

  // Direction the encoder moved + = cw, - = ccw.
  RotaryEncoder::Direction mDirection;

  // FLag set when an encoder movement has been detected.
  bool mChanged;

  // The underlying hardware rotary encoder
  std::unique_ptr<RotaryEncoder> mEncoder;
};

 #endif // ROT_ENCODER_H