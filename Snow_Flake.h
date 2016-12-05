#include <Arduino.h>

void snow_flake() {
  // fade in
  int lowerBrightness = 10;
  for (int i=0; i<lowerBrightness; i++) {
    for (int j=0; j<pixels.numPixels(); j++) {
      pixels.setPixelColor(j, pixels.Color(i, i, i));
    }
    pixels.show();
  }
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    int numLeds = random(1,NUMPIXELS/3);
    int leds[numLeds];
    for (int i=0; i<numLeds; i++) {
      leds[i] = random(NUMPIXELS); //choose random LED to light up
    }
    for (int brightness=lowerBrightness; brightness<256; brightness+=5) {
      for (int i=0; i<(sizeof(leds)/sizeof(int)); i++) {
          pixels.setPixelColor(leds[i], pixels.Color(brightness, brightness, brightness));
      }
      pixels.show();
      delay(20);
    }
    for (int brightness=255; brightness>=lowerBrightness; brightness-=5) {
      for (int i=0; i<(sizeof(leds)/sizeof(int)); i++) {
          pixels.setPixelColor(leds[i], pixels.Color(brightness, brightness, brightness));
      }
      pixels.show();
      delay(20);
    }
  }
}
