/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #include "SpeakerController.h"
 
 #include <Wire.h>

//-----
SpeakerController::SpeakerController(unsigned short speakerPin)
   : mSpeakerPin(speakerPin)
{
   // Enable the speaker
   pinMode(PIN_SPEAKER_ENABLE, OUTPUT);
   digitalWrite(PIN_SPEAKER_ENABLE, HIGH);

   pinMode(mSpeakerPin, OUTPUT);
   digitalWrite(mSpeakerPin, LOW);
}

//-----
SpeakerController::~SpeakerController()
{
}

//-----
void SpeakerController::playTone(unsigned short frequency, unsigned long duration)
{
   tone(mSpeakerPin, frequency, duration);  // tone1 - B5
}
