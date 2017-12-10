#include <Arduino.h>

void red_to_green() {
  int counter = 1;
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    for (int i=0; i<pixels.numPixels(); i++) {
      if (counter%2 > 0) { //if odd number
        if (i%2 > 0) { //if odd number
          pixels.setPixelColor(i, pixels.Color(MAXBRIGHTNESS, 0, 0));
        } else {
          pixels.setPixelColor(i, pixels.Color(0, MAXBRIGHTNESS, 0));
        }
      } else {
        if (i%2 > 0) { //if odd number
          pixels.setPixelColor(i, pixels.Color(0, MAXBRIGHTNESS, 0));
        } else {
          pixels.setPixelColor(i, pixels.Color(MAXBRIGHTNESS, 0, 0));
        }
      }
    }
    pixels.show();
    delay(500);
    counter+=1;
  }
}
