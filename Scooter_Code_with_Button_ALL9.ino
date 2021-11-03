#include <FastLED.h>
#include <OneButton.h>
#include "Arduino.h"

#define NUM_LEDS  21
#define LED_PIN   6
#define BTN_PIN   3
#define BRIGHTNESS 200
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];
uint8_t patternCounter = 0;
bool isRunning = false;
bool isPressed = false;
bool isLongPressed = false;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

// Push button connected between pin 3 and GND (no resistor required)
OneButton btn = OneButton(BTN_PIN, true, true);

#include "MovingDot.h"
#include "RainbowBeat.h"
#include "RedWhiteBlue.h"
#include "Rainbow.h"
#include "RainbowWithGlitter.h"
#include "Confetti.h"
#include "Sinelon.h"
#include "Bpm.h"
#include "Juggle.h"
#include "AddGlitter.h"

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(57600);

  btn.attachClick(nextPattern);
  btn.attachLongPressStart(stopPattern);
}

void loop() {
  if (isLongPressed = true) {
    stopPattern();
//    isRunning = false;
    FastLED.setBrightness(0);
  }
  FastLED.setBrightness(BRIGHTNESS);
  switch (patternCounter) {
    case 0:
      runMovingDot();
      break;
    case 1:
      runRainbowBeat();
      break;
    case 2:
      runRedWhiteBlue();
      break;
    case 3:
      runRainbow();
      break;
    case 4:
      runRainbowWithGlitter();
      break;
    case 5:
      runConfetti();
      break;
    case 6:
      runSinelon();
      break;
    case 7:
      runTroll();
      break;
    case 8:
      runBpm();
      break;            
  }
  FastLED.show();
  btn.tick();
}

void runRainbow() {
  isRunning = true;
  Rainbow rainbow = Rainbow();
  while(isRunning) rainbow.runPattern();
}

//void rainbow() 
//{
  // FastLED's built-in rainbow generator
//  fill_rainbow( leds, NUM_LEDS, gHue, 7);
//}

void runRainbowWithGlitter() {
  isRunning = true;
  RainbowWithGlitter rainbowWithGlitter = RainbowWithGlitter();
  while(isRunning) rainbowWithGlitter.runPattern();
}

//void rainbowWithGlitter() 
//{
//  built-in FastLED rainbow, plus some random sparkly glitter
//  Rainbow();
//  addGlitter(80);
//}

//void addGlitter( fract8 chanceOfGlitter) {
//  if( random8() < chanceOfGlitter) {
//    leds[ random16(NUM_LEDS) ] += CRGB::White;
//  }
//}

void runConfetti() {
  isRunning = true;
  Confetti confetti = Confetti();
  while(isRunning) confetti.runPattern();
}

//void confetti() 
//{
//  random colored speckles that blink in and fade smoothly
//  fadeToBlackBy( leds, NUM_LEDS, 10);
//  int pos = random16(NUM_LEDS);
//  leds[pos] += CHSV( gHue + random8(64), 200, 255);
//}

void runSinelon() {
  isRunning = true;
  Sinelon sinelon = Sinelon();
  while(isRunning) sinelon.runPattern();
}

//void sinelon()
//{
//   a colored dot sweeping back and forth, with fading trails
//  fadeToBlackBy( leds, NUM_LEDS, 20);
//  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
//  leds[pos] += CHSV( gHue, 255, 192);
//}

void runBpm() {
  isRunning = true;
  Bpm bpm = Bpm();
  while(isRunning) bpm.runPattern();
}

//void bpm()
//{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
//  uint8_t BeatsPerMinute = 62;
//  CRGBPalette16 palette = PartyColors_p;
//  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
//  for( int i = 0; i < NUM_LEDS; i++) { //9948
//    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
//  }
//}

//void runTroll() {
//  isRunning = true;
//  Troll troll = Troll();
//  while(isRunning) troll.runPattern();
//}

//void juggle() {
  // eight colored dots, weaving in and out of sync with each other
//  fadeToBlackBy( leds, NUM_LEDS, 20);
//  byte dothue = 0;
//  for( int i = 0; i < 8; i++) {
//    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
//    dothue += 32;
//  }
//}

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 9;      // The number after % should reflect the total # of cases to cycle through
}

void stopPattern() {
  isPressed = true;
//  delay(1000);
  if (isLongPressed = true){
    isRunning = false;
    FastLED.clear();
    FastLED.setBrightness(0);
    FastLED.show();
    btn.tick();
  }
}

void runMovingDot() {
  isRunning = true;
  MovingDot movingDot = MovingDot();
  while(isRunning) movingDot.runPattern();
}

void runRainbowBeat() {
  isRunning = true;
  RainbowBeat rainbowBeat = RainbowBeat();
  while(isRunning) rainbowBeat.runPattern();
}

void runRedWhiteBlue() {
  isRunning = true;
  RedWhiteBlue redWhiteBlue = RedWhiteBlue();
  while(isRunning) redWhiteBlue.runPattern();
}
