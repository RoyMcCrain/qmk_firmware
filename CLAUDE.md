# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## QMK Firmware Overview

QMK (Quantum Mechanical Keyboard) is a keyboard firmware based on the tmk_keyboard firmware, supporting Atmel AVR and ARM controllers. This is a highly modular firmware project with support for hundreds of keyboards.

## Essential Commands

### Building Firmware

**Using QMK CLI (recommended):**
```bash
# Basic compile
qmk compile -kb <keyboard_name> -km <keymap_name>

# Compile and flash
qmk flash -kb <keyboard_name> -km <keymap_name>

# Parallel compilation (faster)
qmk compile -j 0 -kb <keyboard_name> -km <keymap_name>

# Generate compilation database for IDE support
qmk compile --compiledb -kb <keyboard_name> -km <keymap_name>
```

**Using Make (legacy):**
```bash
# Basic syntax: <keyboard_folder>:<keymap>:<target>
make planck/rev6:default
make planck/rev6:default:flash
make clean
```

### Testing

**C Unit Tests:**
```bash
# Run all tests
make test:all

# Run specific test
make test:tap_hold

# Run with debug output
make test:all DEBUG=1
```

**Python Tests:**
```bash
qmk pytest
qmk pytest -t qmk.tests.test_cli_commands
```

### Code Quality

```bash
# Format C code
qmk format-c

# Format Python code
qmk format-python

# Lint keyboard/keymap
qmk lint -kb <keyboard_name> -km <keymap_name>

# Fix text file line endings
qmk format-text
```

### Development Utilities

```bash
# Check environment setup
qmk doctor

# List all keyboards
qmk list-keyboards

# List keymaps for a keyboard
qmk list-keymaps -kb <keyboard_name>

# Get keyboard info
qmk info -kb <keyboard_name>

# Create new keymap
qmk new-keymap -kb <keyboard> -km <keymap_name>

# Create new keyboard
qmk new-keyboard -kb <keyboard_name> -t <mcu_type> -l <layout>

# Debug console output
qmk console
```

## Architecture and Key Directories

```
qmk_firmware/
├── keyboards/           # Keyboard-specific code
│   └── <keyboard>/
│       ├── info.json    # Keyboard metadata and layout
│       ├── rules.mk     # Build configuration
│       └── keymaps/     # User keymaps
│           └── <keymap>/
│               ├── keymap.c
│               └── rules.mk
├── quantum/            # Core QMK functionality
│   ├── quantum.c/h     # Main quantum layer
│   ├── keymap_common.c # Keymap processing
│   └── process_keycode/ # Keycode handlers
├── drivers/            # Hardware drivers (LED, sensors, etc.)
├── platforms/          # Platform-specific code (AVR, ARM)
├── tests/              # Unit test suite
└── builddefs/          # Build system definitions
```

## Key Concepts

### Keyboard Definition Structure
- Each keyboard lives in `keyboards/<keyboard_name>/`
- `info.json` defines the keyboard's physical layout, pins, and features
- `rules.mk` specifies which features to enable/disable
- Keymaps are user-specific layouts in `keymaps/<keymap_name>/`

### Build System
- QMK uses a sophisticated Make-based build system
- `builddefs/` contains the core build logic
- Features are modular and can be enabled/disabled per keyboard
- The build system automatically handles dependency management

### Common Feature Flags (rules.mk)
- `BOOTMAGIC_ENABLE` - Reset keyboard to bootloader
- `MOUSEKEY_ENABLE` - Mouse emulation
- `EXTRAKEY_ENABLE` - Media keys
- `CONSOLE_ENABLE` - Debug console
- `RGBLIGHT_ENABLE` - RGB underglow
- `BACKLIGHT_ENABLE` - Backlight control
- `AUDIO_ENABLE` - Audio/music mode

## Important Notes

1. **Always use absolute paths** when specifying file locations
2. **Test compilation** before making PR - use `qmk compile` to verify changes
3. **Format code** before committing - use `qmk format-c` for C files
4. **Check documentation** at https://docs.qmk.fm for detailed feature information
5. **Keyboard/keymap names** are case-sensitive and use underscores, not hyphens