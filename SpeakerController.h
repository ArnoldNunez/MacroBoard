/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #ifndef SPEAKER_CONTROLLER_H
 #define SPEAKER_CONTROLLER_H

/**
 * Class representing the main application processing.
 */
class SpeakerController
{
public:
  /**
   * Constructor
   * \param speakerPin  The pin associated with the speaker output.
   */
  SpeakerController(unsigned short speakerPin);

  /**
   * Destructor
   */
  ~SpeakerController();

  /**
   * Copy constructor (disabled)
   */
  SpeakerController(const SpeakerController&) = delete;

  /**
   * Play the given frequency for a given duration.
   * \param frequency The tone frequency in Hz
   * \param duration  The duration of the tone in milliseconds
  */
  void playTone(unsigned short frequency, unsigned long duration);

private:
  // The pin associated with the speaker
  unsigned short mSpeakerPin;

};

 #endif // SPEAKER_CONTROLLER_H