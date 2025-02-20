#include "DisplayHandler.h"

static Adafruit_ST7789* display = nullptr;

void initializeDisplay() {
    display = new Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
    display->init(240, 240); // Adjust size to match your display
    display->setRotation(2); // Adjust as needed
    display->fillScreen(ST77XX_BLACK);
}

Adafruit_ST7789* getDisplay() {
    return display;
}

void printText(const char* text, int x, int y, uint16_t color, uint8_t size) {
    if (!display) return;
    display->setTextSize(size);
    display->setTextColor(color);
    display->setCursor(x, y);
    display->print(text);
}

void updateDisplay() {
    // Add display update logic based on current mode
    // This will be called in the main loop
}

void toggleMode() {
    // Add mode toggling logic
}

void handleEncoder(int encoderPosition) {
    // Update display based on encoder position
}