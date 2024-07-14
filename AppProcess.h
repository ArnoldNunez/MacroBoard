/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

#ifndef APP_PROCESS_H
#define APP_PROCESS_H

#include "Context.h"
#include "OLEDController.h"
#include "RotEncoderController.h"
#include "SpeakerController.h"
#include "KeypadController.h"

/**
 * Class representing the main application processing.
 */
class AppProcess
{
public:
  /**
   * Constructor
   */
  AppProcess();

  /**
   * Destructor
   */
  ~AppProcess();

  /**
   * Copy constructor (disabled)
   */
  AppProcess(const AppProcess&) = delete;

  /**
   * Setup for the application.
   */
  void setup();

  /**
   * The application main processing loop.
  */
  void applicationLoop();

private:
   std::unique_ptr<OLEDController> mOledController;
   std::unique_ptr<RotEncoderController> mRotEncoderController;
   std::unique_ptr<SpeakerController> mSpeakerController;
   std::unique_ptr<KeypadController> mKeypadController;
};

 #endif // APP_PROCESS_H