#include <Arduino.h>

void light_climb() {
  for (int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(MAXBRIGHTNESS, 0, 0));
    delay(10);
  }
  t_end = millis() + light_show_duration;
  // Keeps repeating until time is up
  while (millis() < t_end) {
    // Put your code here show here.
    //   
    
    for (int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0, MAXBRIGHTNESS, 0)); // Moderately bright green color.
  
      pixels.show(); // This sends the updated pixel color to the hardware.
  
      delay(100); // Delay for a period of time (in milliseconds).
  
    }

    for (int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(MAXBRIGHTNESS, 0, 0));
      delay(10);
    }
    pixels.show();
    //  
  }  
}
