#include "Arduino.h"

class RainbowWithGlitter {
  public:
    RainbowWithGlitter(){};
    void runPattern();
  private:
};

void addGlitter( fract8 chanceOfGlitter) {
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void RainbowWithGlitter::runPattern() {
  
  // built-in FastLED rainbow, plus some random sparkly glitter
  Rainbow();
  addGlitter(80);
  btn.tick();
  FastLED.show();
}
