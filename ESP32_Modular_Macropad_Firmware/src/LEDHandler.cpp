#include "LEDHandler.h"

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void initializeLED() {
    strip.begin();
    strip.setBrightness(50); // Adjust as needed
    clearAllLEDs();
}

void setLEDColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (index >= NUM_LEDS) return;
    strip.setPixelColor(index, strip.Color(r, g, b));
    strip.show();
}

void setAllLEDs(uint8_t r, uint8_t g, uint8_t b) {
    for(int i = 0; i < NUM_LEDS; i++) {
        strip.setPixelColor(i, strip.Color(r, g, b));
    }
    strip.show();
}

void clearAllLEDs() {
    setAllLEDs(0, 0, 0);
}