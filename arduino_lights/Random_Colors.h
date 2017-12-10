#include <Arduino.h>

void random_colors() {
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    for (int i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pixels.Color(random(0, MAXBRIGHTNESS), random(0, MAXBRIGHTNESS), random(0, MAXBRIGHTNESS)));
    }
    delay(2);
    pixels.show();

    delay(10);
  }
}
