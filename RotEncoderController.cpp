/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#include "RotEncoderController.h"

#include <list>

// Rotarty encoder interrupt list
std::list<RotaryEncoder*> ENCODER_INTERRUPTS;

void encoderInterrupt() 
{
   for (const auto& encoder : ENCODER_INTERRUPTS)
   {
    encoder->tick();
   }
}

//-----
RotEncoderController::RotEncoderController(unsigned short pin1, unsigned short pin2)
   : mPin1(pin1),
     mPin2(pin2),
     mNewPos(0),
     mOldPos(0),
     mDirection(RotaryEncoder::Direction::NOROTATION),
     mChanged(false),
     mEncoder(nullptr)
{
   // Instantiate the library rotary encoder
   mEncoder = std::make_unique<RotaryEncoder>(mPin1, mPin2, RotaryEncoder::LatchMode::FOUR3);
   
   // Set rotary encoder inputs to pullup
   // input HIGH means button is release
   // input LOW means button is pressed
   pinMode(mPin1, INPUT_PULLUP);
   pinMode(mPin2, INPUT_PULLUP);

   // Attach interrupts to the encoder digital pins
   attachInterrupt(digitalPinToInterrupt(mPin1), encoderInterrupt, CHANGE);
   attachInterrupt(digitalPinToInterrupt(mPin2), encoderInterrupt, CHANGE);

   ENCODER_INTERRUPTS.push_back(mEncoder.get());
}

//-----
RotEncoderController::~RotEncoderController()
{
}

//-----
void RotEncoderController::process()
{
   // Update underlying hardware encoder processing
   mEncoder->tick();

   // Update encoder state
   int newPos = mEncoder->getPosition();
   if (newPos != mNewPos)
   {
      mOldPos = mNewPos;
      mNewPos = newPos;
      mDirection = mEncoder->getDirection();
      mChanged = true;
   }
   else
   {
      mChanged = false;
   }
}
