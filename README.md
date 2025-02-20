<div align="center">

# Modular ESP32 Macropad System

</div>

<div align="center">

![Macropad Preview](assets/macropad-preview.png)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-IDE-orange.svg)](https://platformio.org/)
[![Svelte](https://img.shields.io/badge/Svelte-Frontend-red.svg)](https://svelte.dev)
[![ESP32](https://img.shields.io/badge/ESP32-S3-blue.svg)](https://www.espressif.com/)

</div>

## 🚀 Overview
A modular, low-profile macropad system powered by the ESP32-S3. Featuring hot-swappable switches, programmable layers, and a modern web interface for configuration.

### 🎯 Key Features
- **Modular Design**: Mix and match different modules to create your perfect setup
  - Full-size modules (1x1)
  - Half-size modules (1x0.5)
  - Quarter-size modules (0.25x0.25)
- **Advanced Hardware**
  - Low-profile Gateron switches (hot-swappable)
  - Per-key RGB LEDs
  - OLED/LCD displays (module dependent)
  - High-resolution rotary encoders
  - Premium sliders
- **Smart Software**
  - 4 programmable layers
  - DuckyScript macro support
  - Real-time configuration via USB
  - Custom animations and lighting effects

## 📦 Available Modules

### Full-Size Modules (1x1)
- **Main Control**: 18 keys, display, rotary encoder
- **Slider Bank**: 4 sliders, 2 encoders
- **Encoder Bank**: 6 high-resolution encoders

### Half-Size Modules (1x0.5)
- **Compact Sliders**: 2-3 sliders
- **Compact Encoders**: 2-3 encoders
- **Button Grid**: 8-12 keys

### Quarter-Size Modules (0.25x0.25)
- **Mini Buttons**: 4 keys
- **Single Encoder**: 1 encoder with button

## 🛠️ Development Setup

### Prerequisites
```bash
# Install Node.js dependencies
npm install

# Install PlatformIO CLI
pip install platformio

# Install KiCad 7.0 or later
# Download from: https://kicad.org/download/
```

### Building the Firmware
```bash
# Clone the repository
git clone https://github.com/yourusername/esp32-macropad
cd esp32-macropad

# Build firmware
pio run

# Upload firmware
pio run -t upload

# Upload filesystem
pio run -t uploadfs
```

### Running the Frontend
```bash
# Development mode
npm run dev

# Build for production
npm run build
```

## 📝 Configuration

### Module Detection
The system automatically detects connected modules and their capabilities:
- Number and type of inputs (keys, encoders, sliders)
- LED configuration
- Display presence
- Available features

### Layer Configuration
Each module supports 4 programmable layers:
1. Default Layer
2. Function Layer
3. Macro Layer
4. Custom Layer

### DuckyScript Example
```ducky
REM Example macro for opening task manager
WINDOWS
DELAY 100
STRING taskmgr
ENTER
```

## 🔧 Hardware Specifications

### PCB Details
- **MCU**: ESP32-S3-MINI-N4R2
- **Flash**: 4MB
- **PSRAM**: 2MB
- **USB**: Native USB
- **Switch Support**: Gateron Low Profile
- **LED Type**: WS2812B

### Power Requirements
- **Voltage**: 5V via USB-C
- **Current**: 
  - Minimum: 100mA
  - Maximum: 500mA (all LEDs on)

## 📁 Project Structure
```
esp32-macropad/
├── firmware/           # ESP32 firmware
│   ├── src/           # Source files
│   └── lib/           # Libraries
├── hardware/          # Hardware design files
│   ├── kicad/        # PCB design
│   └── cases/        # 3D printable cases
├── 3d_files/         # 3D Design Files
│   ├── fusion360/    # Fusion 360 source files
│   ├── step/         # STEP files for CAD compatibility
│   ├── stl/          # Ready to print STL files
│   └── renders/      # Rendered images of designs
├── frontend/         # Svelte frontend
└── docs/            # Documentation
```

## 🔧 Hardware Specifications

### Power System
- **Input Options**:
  - USB-C: 5V for direct power
  - Battery: 3.7V LiPo/Li-ion support
- **Power Management**:
  - Buck/Boost Converter: 3.3V regulation for ESP32
  - 5V Boost: LED power when on battery
  - Low power mode support
- **Current Requirements**:
  - USB Mode: 500mA max (all LEDs on)
  - Battery Mode: 150-400mA depending on LED usage
  - Sleep Mode: <100µA

### PCB Features
- **MCU**: ESP32-S3-MINI-N4R2
- **Power Management**:
  - Battery charging circuit
  - Power source auto-switching
  - Battery monitoring
- **LED Support**: WS2812B (5V)
- **Switch Support**: Gateron Low Profile

## 🤝 Contributing

### Getting Started
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to your fork
5. Submit a pull request

### Development Guidelines
- Follow the coding style guide
- Add tests for new features
- Update documentation
- Keep commits atomic and descriptive

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments
- ESP32 Community
- Mechanical Keyboard Community
- Open Source Hardware Community
- All Contributors

## 📞 Support & Contact
- Create an [Issue](https://github.com/yourusername/esp32-macropad/issues)
