# SampleJucePlugin

A minimal JUCE‑powered VST3 audio plugin demonstrating a pass‑through processor and basic GUI.

## Features

- Stereo audio pass‑through (input copied to output).
- Simple dark‑grey editor window showing plugin name.
- CMake‑based build using either a local JUCE clone or FetchContent.

## Prerequisites

- **C++ toolchain**: GCC or Clang (e.g. `build-essential` on Ubuntu).
- **CMake** ≥ 3.15 and Ninja (or another generator).
- **JUCE framework**:
  - Option A: Local clone at `~/JUCE` with `extras/Build/JUCE/CMakeLists.txt`.
  - Option B: Automatically fetched via CMake’s `FetchContent`.
- **VST3 SDK** (only if you need to build against Steinberg’s headers; otherwise JUCE bundles a wrapper).

## Directory Structure

```
SampleJucePlugin/
├── CMakeLists.txt
├── Source/
│   ├── PluginProcessor.cpp
│   ├── PluginProcessor.h
│   ├── PluginEditor.cpp
│   └── PluginEditor.h
└── README.md
```

## Build Instructions

1. **Clone or fetch JUCE** (if using local)
   ```bash
   git clone https://github.com/juce-framework/JUCE.git ~/JUCE
   ```
2. **Create build directory**
   ```bash
   mkdir build && cd build
   ```
3. **Configure with CMake**
   - **Local JUCE**:
     ```bash
     cmake -G Ninja \
       -DCMAKE_BUILD_TYPE=Debug \
       -DJUCE_DIR=$HOME/JUCE \
       ..
     ```
   - **FetchContent JUCE**:
     ```bash
     cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
     ```
4. **Build**
   ```bash
   cmake --build .
   ```

## Output

- After a successful build, find your plugin bundle at:
  ```
  build/SampleJucePlugin/<BuildConfig>/VST3/SampleJucePlugin.vst3
  ```
- Load it in any VST3‑compatible host (e.g., REAPER, Ardour, Carla).

## Customization

- **DSP Logic**: Edit `Source/PluginProcessor.cpp` in `processBlock()`.
- **GUI**: Modify `Source/PluginEditor.cpp` in `paint()` and `resized()`.
- **Formats**: In `CMakeLists.txt`, change `FORMATS` (e.g., add `AU`, `AAX`).

## Debugging & IDE Integration

- **VS Code**: Use CMake Tools extension; configure `.vscode/settings.json`:
  ```json
  {
    "cmake.generator": "Ninja",
    "cmake.buildDirectory": "${workspaceFolder}/build"
  }
  ```
- **Debug host**: Set your DAW/host executable as launch target in `launch.json`.

---

For full examples and advanced features, see the official JUCE docs: [https://juce.com/learn/documentation](https://juce.com/learn/documentation)

