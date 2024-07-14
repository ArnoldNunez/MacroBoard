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
   pinMode(mSpeakerPin, OUTPUT);
   digitalWrite(mSpeakerPin, HIGH);
}

//-----
SpeakerController::~SpeakerController()
{
}

//-----
void SpeakerController::playTone(unsigned short frequency, unsigned long duration)
{
   pinMode(PIN_SPEAKER, OUTPUT);
   digitalWrite(PIN_SPEAKER, LOW);
   tone(PIN_SPEAKER, 988, 100);  // tone1 - B5
   delay(100);
   tone(PIN_SPEAKER, 1319, 200); // tone2 - E6
   delay(200);
}
