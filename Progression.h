#include <Arduino.h>

void progression() {
  int counter = 1;
  t_end = millis() + light_show_duration;
  while (millis() < t_end) {
    for (int i=0; i<pixels.numPixels(); i++) {
      if(counter%2>0) { // if odd
        pixels.setPixelColor(i, pixels.Color(MAXBRIGHTNESS, 0, 0));
      } else { // if even
        pixels.setPixelColor(i, pixels.Color(0, MAXBRIGHTNESS, 0));
      }
      pixels.show();
      delay(100);
    }
    counter+=1;
  }
}

