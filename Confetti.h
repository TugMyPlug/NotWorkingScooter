#include "Arduino.h"

class Confetti {
  public:
    Confetti(){};
    void runPattern();
  private:
};

void Confetti::runPattern() {
  
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);

  btn.tick();
  FastLED.show();
}
