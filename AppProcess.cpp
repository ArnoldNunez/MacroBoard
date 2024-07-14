/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#include "AppProcess.h"

#include <Wire.h>

//-----
AppProcess::AppProcess()
   : mOledController(nullptr),
     mRotEncoderController(nullptr),
     mSpeakerController(nullptr),
     mKeypadController(nullptr)
{
}

//-----
AppProcess::~AppProcess()
{
}

//-----
void AppProcess::setup()
{
    // Setup serial connection
    Serial.begin(115200);
    delay(100); // RP2040 delay is not a bad idea

    Serial.println("Adafruit Macropad with RP2040");

    // Start pixels!
    mKeypadController = std::make_unique<KeypadController>();
    mKeypadController->initializeLEDs();
}

void AppProcess::applicationLoop()
{
}
