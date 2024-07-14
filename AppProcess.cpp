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

    // Start pixels
    mKeypadController = std::make_unique<KeypadController>();
    mKeypadController->initializeLEDs();

    // Start OLED
    mOledController = std::make_unique<OLEDController>(128, 64);
    mOledController->setup();

    // Start Rotary Encoder
    mRotEncoderController = std::make_unique<RotEncoderController>(PIN_ROTA, PIN_ROTB);

    // Start speaker
    mSpeakerController = std::make_unique<SpeakerController>(PIN_SPEAKER);


    // Play setup tune
    mSpeakerController->playTone(988, 100);
    delay(200);
    mSpeakerController->playTone(1319, 200);
    delay(200);
}

void AppProcess::applicationLoop()
{
  // Update keypad state
  mKeypadController->process();
  std::vector<KeySwitch*> keyState = mKeypadController->getState();

  // Render OLED updates
  mOledController->render(keyState);

  // Update OLED based on keypad state
  // mOledController->drawKeypadState(mKeypadController->getState());
}
