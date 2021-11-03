#include "Arduino.h"

class AddGlitter {
  public:
    AddGlitter() {};
    void runPattern();
  private:
};

void AddGlitter::runPattern() {

  void addGlitter( fract8 chanceOfGlitter) {
    if ( random8() < chanceOfGlitter) {
      leds[ random16(NUM_LEDS) ] += CRGB::White;
    }
  }
  btn.tick();
  FastLED.show();
}
