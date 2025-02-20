#include "DisplayHandler.h"
#include "KeyHandler.h"
#include "EncoderHandler.h"
#include "LEDHandler.h"
#include "SerialHandler.h"
#include "ModuleInfo.h"

KeyHandler* keyHandler;

void setup() {
    // Initialize module info first
    initializeModuleInfo();
    
    // Initialize serial handler
    initializeSerialHandler();
    
    // Initialize display
    initializeDisplay();
    
    // Initialize key matrix
    setupKeys(); // This will create the keyHandler instance
    
    // Initialize encoder
    initializeEncoder();
    
    // Initialize LEDs
    initializeLED();
    
    // Initial display setup
    Adafruit_ST7789* display = getDisplay();
    display->fillScreen(ST77XX_BLACK);
    printText("System Ready", 10, 10, ST77XX_WHITE, 2);
}

void loop() {
    // Handle serial commands
    handleSerialCommands();
    
    // Handle key inputs
    char key = keyHandler->getKey();
    if (key != NO_KEY) {
        // Get key index and handle press
        handleKeyPress(key);
    }
    
    // Handle encoder
    handleEncoderMovement();
    
    // Update display
    updateDisplay();
}

void handleKeyPress(char key) {
    // Find key index in your mapping
    int keyIndex = getKeyIndex(key);
    if (keyIndex >= 0 && keyIndex < 18) {
        // Set LED color from config
        uint32_t color = currentConfig.keys[keyIndex].ledColor;
        setLEDColor(keyIndex, 
            (color >> 16) & 0xFF,  // Red
            (color >> 8) & 0xFF,   // Green
            color & 0xFF           // Blue
        );
        
        // Send key press event over serial
        Serial.printf("{\"event\":\"keyPress\",\"key\":%d}\n", keyIndex);
    }
}