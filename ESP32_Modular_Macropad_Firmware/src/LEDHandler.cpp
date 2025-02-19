// LEDHandler.cpp
#include "LEDHandler.h"

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void initializeLED() {
    strip.begin();
    strip.show();
}

void setLEDColor(uint8_t r, uint8_t g, uint8_t b) {
    strip.setPixelColor(0, strip.Color(r, g, b));
    strip.show();
}