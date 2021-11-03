#include "Arduino.h"

class Rainbow {
  public:
    Rainbow(){};
    void runPattern();
  private:
};

void Rainbow::runPattern() {

  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  
  btn.tick();
  FastLED.show();
}
