#include <Arduino.h>

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void rainbow() { 
  uint16_t i, j;
  t_end = millis() + light_show_duration;
  while(millis() < t_end) {
    for(j=0; j<256; j++) {
      for(i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, Wheel((i+j) & 255));
      }
      pixels.show();
      delay(100);
    }    
  }
}
