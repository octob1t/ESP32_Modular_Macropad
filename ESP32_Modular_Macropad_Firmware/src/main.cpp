// main.cpp
#include "DisplayHandler.h"
#include "KeypadHandler.h"
#include "EncoderHandler.h"
#include "LEDHandler.h"

void setup() {
    Serial.begin(115200);
    
    // Initialize all components
    initializeDisplay();
    initializeKeypad();
    initializeEncoder();
    initializeLED();
    
    // Initial display setup
    Adafruit_ST7789* display = getDisplay();
    display->fillScreen(ST77XX_BLACK);
    printText("System Ready", 10, 10, ST77XX_WHITE, 2);
}

void loop() {
    // Handle keypad input
    char key = getKey();
    if (key) {
        // Handle key press
        Serial.println(key);
    }
    
    // Handle encoder
    handleEncoderMovement();
    
    // Update display as needed
    updateDisplay();
    
    // Example LED feedback
    if (key) {
        setLEDColor(255, 0, 0);  // Red when key pressed
        delay(100);
        setLEDColor(0, 0, 0);    // Off
    }
}