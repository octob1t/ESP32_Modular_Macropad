// DisplayHandler.h
#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// Pin definitions for the display
#define TFT_CS    37   // Chip select pin
#define TFT_DC    39   // Data/command pin
#define TFT_SCLK  40   // Serial clock pin
#define TFT_MOSI  38   // Master out, slave in pin
#define TFT_RST   15   // Reset pin


// Function declarations
void initializeDisplay();
Adafruit_ST7789* getDisplay();
void printText(const char* text, int x, int y, uint16_t color, uint8_t size);
void updateDisplay();
void toggleMode();
void handleEncoder(int encoderPosition);

#endif // DISPLAY_HANDLER_H
