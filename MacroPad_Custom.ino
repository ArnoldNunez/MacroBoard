#include <Adafruit_SH110X.h>
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include <Wire.h>
#include <RP2040USB.h>
// #include <device/usbd.h>
#include <tusb.h>


#include "AppProcess.h"

AppProcess app;

void setup() {
  app.setup();

  // // We will use I2C for scanning the Stemma QT port
  // Wire.begin();
}

// uint8_t j = 0;
// bool i2c_found[128] = {false};

void loop() {
  app.applicationLoop();
  
  // // Encoder processing
  // encoder.tick();          // check the encoder
  // int newPos = encoder.getPosition();
  // if (encoder_pos != newPos) {
  //   Serial.print("Encoder:");
  //   Serial.print(newPos);
  //   Serial.print(" Direction:");
  //   Serial.println((int)(encoder.getDirection()));
  //   encoder_pos = newPos;
  // }
  // display.setCursor(0, 8);
  // display.print("Rotary encoder: ");
  // display.print(encoder_pos);

  // // Scanning takes a while so we don't do it all the time
  // if ((j & 0x3F) == 0) {
  //   Serial.println("Scanning I2C: ");
  //   Serial.print("Found I2C address 0x");
  //   for (uint8_t address = 0; address <= 0x7F; address++) {
  //     Wire.beginTransmission(address);
  //     i2c_found[address] = (Wire.endTransmission () == 0);
  //     if (i2c_found[address]) {
  //       Serial.print("0x");
  //       Serial.print(address, HEX);
  //       Serial.print(", ");
  //     }
  //   }
  //   Serial.println();
  // }
  
  // display.setCursor(0, 16);
  // display.print("I2C Scan: ");
  // for (uint8_t address=0; address <= 0x7F; address++) {
  //   if (!i2c_found[address]) continue;
  //   display.print("0x");
  //   display.print(address, HEX);
  //   display.print(" ");
  // }
  
  // // check encoder press
  // display.setCursor(0, 24);
  // if (!digitalRead(PIN_SWITCH)) {
  //   Serial.println("Encoder button");
  //   display.print("Encoder pressed ");
  //   pixels.setBrightness(255);     // bright!
  // } else {
  //   pixels.setBrightness(80);
  // }

  // // LED Rainbow effect
  // for(int i=0; i< pixels.numPixels(); i++) {
  //   pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
  // }
  
  // // Show which switch is pressed
  // for (int i=1; i<=12; i++) {
  //   if (!digitalRead(i)) { // switch pressed!
  //     Serial.print("Switch "); Serial.println(i);
  //     pixels.setPixelColor(i-1, 0xFFFFFF);  // make white
  //     // move the text into a 3x4 grid
  //     display.setCursor(((i-1) % 3)*48, 32 + ((i-1)/3)*8);
  //     display.print("KEY");
  //     display.print(i);
  //   }
  // }

  // // show neopixels, incredment swirl
  // pixels.show();
  // j++;

  // // display oled
  // display.display();
}





// // Input a value 0 to 255 to get a color value.
// // The colours are a transition r - g - b - back to r.
// uint32_t Wheel(byte WheelPos) {
//   if(WheelPos < 85) {
//    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//   } else if(WheelPos < 170) {
//    WheelPos -= 85;
//    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//   } else {
//    WheelPos -= 170;
//    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//   }
// }