#include "SerialHandler.h"
#include <SPIFFS.h>

MacropadConfig currentConfig;

void initializeSerialHandler() {
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed");
        return;
    }
    
    // Load initial configuration
    currentConfig = loadConfiguration();
    
    // Set up Serial for USB communication
    Serial.begin(115200);
}

void handleSerialCommands() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        
        // Parse JSON command
        DynamicJsonDocument doc(2048);
        DeserializationError error = deserializeJson(doc, command);
        
        // Send initial handshake response for new connections
        if (command == "?") {
            Serial.println("{\"status\":\"ready\"}");
            return;
        }
        
        if (error) {
            Serial.println("{\"error\": \"Invalid JSON command\"}");
            return;
        }
        
        // Handle different command types
        String cmdType = doc["cmd"].as<String>();
        
        if (cmdType == "getModuleInfo") {
            Serial.println(getModuleInfoJson());
        }
        else if (cmdType == "getConfig") {
            sendCurrentConfig();
        }
        else if (cmdType == "setConfig") {
            // Update configuration
            JsonObject config = doc["config"];
            
            for (int i = 0; i < 18; i++) {
                currentConfig.keys[i].keyName = config["keys"][i]["name"].as<String>();
                currentConfig.keys[i].ledColor = config["keys"][i]["color"].as<uint32_t>();
                currentConfig.keys[i].macroSequence = config["keys"][i]["macro"].as<String>();
            }
            currentConfig.encoderMode = config["encoder"]["mode"].as<int>();
            currentConfig.encoderFunction = config["encoder"]["function"].as<String>();
            
            saveConfiguration(currentConfig);
            Serial.println("{\"status\": \"Configuration updated\"}");
        }
    }
}

void sendCurrentConfig() {
    DynamicJsonDocument doc(2048);
    
    // Convert current configuration to JSON
    for (int i = 0; i < 18; i++) {
        doc["keys"][i]["name"] = currentConfig.keys[i].keyName;
        doc["keys"][i]["color"] = currentConfig.keys[i].ledColor;
        doc["keys"][i]["macro"] = currentConfig.keys[i].macroSequence;
    }
    doc["encoder"]["mode"] = currentConfig.encoderMode;
    doc["encoder"]["function"] = currentConfig.encoderFunction;
    
    String response;
    serializeJson(doc, response);
    Serial.println(response);
}

void saveConfiguration(const MacropadConfig& config) {
    File file = SPIFFS.open("/config.json", "w");
    if (!file) {
        Serial.println("{\"error\": \"Failed to open config file for writing\"}");
        return;
    }
    
    DynamicJsonDocument doc(2048);
    for (int i = 0; i < 18; i++) {
        doc["keys"][i]["name"] = config.keys[i].keyName;
        doc["keys"][i]["color"] = config.keys[i].ledColor;
        doc["keys"][i]["macro"] = config.keys[i].macroSequence;
    }
    doc["encoder"]["mode"] = config.encoderMode;
    doc["encoder"]["function"] = config.encoderFunction;
    
    serializeJson(doc, file);
    file.close();
}

MacropadConfig loadConfiguration() {
    MacropadConfig config;
    
    File file = SPIFFS.open("/config.json", "r");
    if (!file) {
        Serial.println("{\"status\": \"No config file found, using defaults\"}");
        // Set default values
        for (int i = 0; i < 18; i++) {
            config.keys[i].keyName = "Key " + String(i + 1);
            config.keys[i].ledColor = 0x00FF00; // Green
            config.keys[i].macroSequence = "";
        }
        config.encoderMode = 0;
        config.encoderFunction = "volume";
        return config;
    }
    
    DynamicJsonDocument doc(2048);
    DeserializationError error = deserializeJson(doc, file);
    file.close();
    
    if (error) {
        Serial.println("{\"error\": \"Failed to parse config file\"}");
        return config;
    }
    
    // Load configuration from JSON
    for (int i = 0; i < 18; i++) {
        config.keys[i].keyName = doc["keys"][i]["name"].as<String>();
        config.keys[i].ledColor = doc["keys"][i]["color"].as<uint32_t>();
        config.keys[i].macroSequence = doc["keys"][i]["macro"].as<String>();
    }
    config.encoderMode = doc["encoder"]["mode"].as<int>();
    config.encoderFunction = doc["encoder"]["function"].as<String>();
    
    return config;
}