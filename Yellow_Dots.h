#include <Arduino.h>

void yellow_dots() {
  // Start white
  for (int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(20, 20, 20));
  }
  pixels.show();
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    //
    for (int i=0; i<NUMPIXELS; i++) {
      int pixel = random(NUMPIXELS-i,NUMPIXELS); // chose random pixel
      pixels.setPixelColor(pixel, pixels.Color(MAXBRIGHTNESS, MAXBRIGHTNESS, 0));
      pixels.show();
      delay(50);
    }
    // Reset
    for (int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(20, 20, 20));
    }
    pixels.show();
    //
  }
}

