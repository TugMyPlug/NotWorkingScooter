#include "Arduino.h"

class Sinelon {
  public:
    Sinelon(){};
    void runPattern();
  private:
};

void Sinelon::runPattern() {
  
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);

  btn.tick();
  FastLED.show();
}
