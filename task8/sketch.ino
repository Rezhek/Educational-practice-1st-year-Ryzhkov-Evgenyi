#include <Adafruit_NeoPixel.h>

#define PIN_MATRIX   3
#define NUM_LEDS    64
Adafruit_NeoPixel matrix = Adafruit_NeoPixel(NUM_LEDS, PIN_MATRIX, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(255);
}

void RunPixel() {
  for (int i = 0; i < NUM_LEDS; i++) {
    matrix.clear();
    matrix.setPixelColor(i, matrix.Color(255, 0, 0));
    matrix.show();
    delay(100);
  }
}

void loop() {
  RunPixel();
}