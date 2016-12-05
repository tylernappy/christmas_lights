#include <Arduino.h>

void spiral_dots() {
  int index_0, index_1, index_2;
  int lowerBrightness = 10;
  for (int i=0; i<lowerBrightness; i++) {
    for (int j=0; j<pixels.numPixels(); j++) {
      pixels.setPixelColor(j, pixels.Color(i, i, i));
    }
    pixels.show();
  }
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    for (int i=0; i<pixels.numPixels(); i++){
      if (i == NUMPIXELS-2) {
        index_0 = i;
        index_1 = i+1;
        index_2 = 0;
      } else if (i == NUMPIXELS-1) {
        index_0 = i;
        index_1 = 0;
        index_2 = 1;
      } else {
        index_0 = i;
        index_1 = i+1;
        index_2 = i+2;
      }
      pixels.setPixelColor(index_0, pixels.Color(0, MAXBRIGHTNESS, 0));
      pixels.setPixelColor(index_1, pixels.Color(MAXBRIGHTNESS, 0, 0));
      pixels.setPixelColor(index_2, pixels.Color(0, MAXBRIGHTNESS, 0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(index_0, pixels.Color(lowerBrightness, lowerBrightness, lowerBrightness));
      pixels.setPixelColor(index_1, pixels.Color(lowerBrightness, lowerBrightness, lowerBrightness));
      pixels.setPixelColor(index_2, pixels.Color(lowerBrightness, lowerBrightness, lowerBrightness));
      pixels.show();
    }
  }
}

