#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 240
#define MAXBRIGHTNESS 180

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned long t_end; // end time to know when to move onto next function
unsigned long light_show_duration = 60000; // 60 seconds for each light show

// Include functions
#include "Light_Climb.h"
#include "Snow_Flake.h"
#include "Rainbow.h"
#include "Progression.h"
#include "Red_To_Green.h"
#include "Yellow_Dots.h"
#include "Spiral_Dots.h"

void setup() {
  pixels.begin();
}

void loop() {
  spiral_dots();
  yellow_dots();
  snow_flake();
  red_to_green();
  progression();
  rainbow();
  light_climb();
}
