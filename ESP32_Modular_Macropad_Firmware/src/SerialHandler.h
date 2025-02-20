#ifndef SERIAL_HANDLER_H
#define SERIAL_HANDLER_H

#include <ArduinoJson.h>
#include <SPIFFS.h>
#include "ModuleInfo.h"

// Configuration structure
struct MacropadConfig {
    struct KeyConfig {
        String keyName;
        uint32_t ledColor;
        String macroSequence;
    };
    KeyConfig keys[18];
    int encoderMode;
    String encoderFunction;
};

// Function declarations
void initializeSerialHandler();
void handleSerialCommands();
void saveConfiguration(const MacropadConfig& config);
MacropadConfig loadConfiguration();
void sendCurrentConfig();

extern MacropadConfig currentConfig;

#endif // SERIAL_HANDLER_H