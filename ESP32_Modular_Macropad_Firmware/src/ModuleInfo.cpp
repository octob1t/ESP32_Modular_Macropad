#include "ModuleInfo.h"
#include <ArduinoJson.h>

ModuleCapabilities currentModule;

void initializeModuleInfo() {
    // Get unique ID from ESP32
    uint64_t chipId = ESP.getEfuseMac();
    char uniqueId[13];
    snprintf(uniqueId, 13, "%04X%08X", (uint16_t)(chipId >> 32), (uint32_t)chipId);

    // Initialize module capabilities for Main Module
    currentModule = {
        .type = ModuleType::FULL_MAIN,
        .size = ModuleSize::FULL,
        .hasDisplay = true,
        .numButtons = 18,
        .numLEDs = 18,
        .numRotaryEncoders = 1,
        .numSliders = 0,
        .numAS5600Encoders = 0,
        .moduleVersion = "1.0.0",
        .uniqueId = String(uniqueId),
        .customName = ""
    };
}

ModuleCapabilities getModuleCapabilities() {
    return currentModule;
}

String getModuleInfoJson() {
    DynamicJsonDocument doc(512);
    
    doc["type"] = static_cast<int>(currentModule.type);
    doc["typeName"] = getModuleTypeName(currentModule.type);
    doc["size"] = static_cast<int>(currentModule.size);
    doc["sizeName"] = getModuleSizeName(currentModule.size);
    doc["hasDisplay"] = currentModule.hasDisplay;
    doc["numButtons"] = currentModule.numButtons;
    doc["numLEDs"] = currentModule.numLEDs;
    doc["numRotaryEncoders"] = currentModule.numRotaryEncoders;
    doc["numSliders"] = currentModule.numSliders;
    doc["numAS5600Encoders"] = currentModule.numAS5600Encoders;
    doc["moduleVersion"] = currentModule.moduleVersion;
    doc["uniqueId"] = currentModule.uniqueId;
    doc["customName"] = currentModule.customName;
    
    String output;
    serializeJson(doc, output);
    return output;
}

const char* getModuleTypeName(ModuleType type) {
    switch(type) {
        // Full-size modules
        case ModuleType::FULL_MAIN:
            return "Main Control";
        case ModuleType::FULL_SLIDER:
            return "Slider Bank";
        case ModuleType::FULL_ENCODER:
            return "Encoder Bank";
        
        // Half-size modules
        case ModuleType::HALF_SLIDER:
            return "Compact Sliders";
        case ModuleType::HALF_ENCODER:
            return "Compact Encoders";
        case ModuleType::HALF_BUTTON:
            return "Button Grid";
        
        // Quarter-size modules
        case ModuleType::QUARTER_BUTTON:
            return "Mini Buttons";
        case ModuleType::QUARTER_ENCODER:
            return "Single Encoder";
        
        // Special
        case ModuleType::CUSTOM:
            return "Custom Module";
            
        default:
            return "Unknown Module";
    }
}

const char* getModuleSizeName(ModuleSize size) {
    switch(size) {
        case ModuleSize::FULL:
            return "Full (1x1)";
        case ModuleSize::HALF:
            return "Half (1x0.5)";
        case ModuleSize::QUARTER:
            return "Quarter (0.5x0.5)";
        default:
            return "Unknown Size";
    }
}