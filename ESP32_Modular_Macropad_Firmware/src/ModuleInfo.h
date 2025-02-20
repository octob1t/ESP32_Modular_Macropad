// ModuleInfo.h
#ifndef MODULE_INFO_H
#define MODULE_INFO_H

#include <Arduino.h>

enum class ModuleSize {
    FULL = 0,    // 1x1 - Full square
    HALF = 1,    // 1x0.5 - Half square
    QUARTER = 2  // 0.5x0.5 - Quarter square
};

enum class ModuleType {
    // Full-size modules (1x1)
    FULL_MAIN = 0,      // Main module with display and controls
    FULL_SLIDER = 1,    // Multiple sliders
    FULL_ENCODER = 2,   // Multiple large encoders
    
    // Half-size modules (1x0.5)
    HALF_SLIDER = 10,   // 2-3 sliders
    HALF_ENCODER = 11,  // 2-3 encoders
    HALF_BUTTON = 12,   // Button grid
    
    // Quarter-size modules (0.5x0.5)
    QUARTER_BUTTON = 20,  // Small button cluster
    QUARTER_ENCODER = 21, // Single encoder
    
    // Special
    CUSTOM = 99  // Custom/third-party modules
};

struct ModuleCapabilities {
    ModuleType type;
    ModuleSize size;
    bool hasDisplay;
    uint8_t numButtons;
    uint8_t numLEDs;
    uint8_t numRotaryEncoders;  // Standard rotary encoders
    uint8_t numSliders;         // Linear potentiometers
    uint8_t numAS5600Encoders;  // Magnetic absolute encoders
    String moduleVersion;
    String uniqueId;            // Derived from chip ID
    String customName;          // For CUSTOM type modules
    uint8_t numLayers;          // Number of available layers
};

// Function declarations
void initializeModuleInfo();
ModuleCapabilities getModuleCapabilities();
String getModuleInfoJson();
const char* getModuleTypeName(ModuleType type);
const char* getModuleSizeName(ModuleSize size);

extern ModuleCapabilities currentModule;

#endif // MODULE_INFO_H