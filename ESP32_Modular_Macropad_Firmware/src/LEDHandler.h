#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include <Adafruit_NeoPixel.h>

#define LED_PIN 7     // LED_GPIO
#define NUM_LEDS 18   // Updated for main module

void initializeLED();
void setLEDColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void setAllLEDs(uint8_t r, uint8_t g, uint8_t b);
void clearAllLEDs();
extern Adafruit_NeoPixel strip;

#endif