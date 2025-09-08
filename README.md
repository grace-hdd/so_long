# so_long

A 2D Pac-Man style game built with C and the minilibx graphics library.

## Overview

This project implements a simple 2D game where the player must collect all collectibles before reaching the exit. The game features multiple players, enemy ghosts with AI, animations, and cross-platform support.

## Features

- **Multiple Players**: Support for multiple Pac-Man characters
- **Enemy AI**: Ghosts that chase the player using pathfinding algorithms
- **Animations**: Smooth character animations and visual effects
- **Cross-Platform**: Works on both macOS and Linux
- **Multiple Maps**: 30+ different test maps included
- **Score System**: Track moves and performance

## Game Rules

The game follows these rules:
- Only `P` (player), `1` (wall), `0` (empty), `C` (collectible), and `E` (exit) characters are allowed
- The map must be rectangular (all rows same length)
- Must have exactly one player, at least one exit, and at least one collectible
- The map must be completely surrounded by walls
- Player must collect all collectibles before reaching the exit

## Installation

### Prerequisites

- macOS or Linux
- minilibx library
- gcc compiler

### macOS Setup

1. Install XQuartz:
   ```bash
   brew install --cask xquartz
   ```

2. Download minilibx from 42 intranet or GitHub

3. Install minilibx:
   ```bash
   # Extract minilibx_opengl.tgz
   cd minilibx_opengl
   make
   sudo cp mlx.h /usr/local/include
   sudo cp libmlx.a /usr/local/lib
   ```

### Linux Setup

1. Install dependencies:
   ```bash
   sudo apt-get install libx11-dev libxext-dev
   ```

2. Install minilibx:
   ```bash
   git clone https://github.com/42Paris/minilibx-linux.git
   cd minilibx-linux
   make
   sudo cp mlx.h /usr/include
   sudo cp libmlx.a /usr/lib
   ```

## Building

```bash
make
```

## Usage

```bash
# Run with a specific map
./bin/so_long tests/classic.ber

# Run with multiple maps
make play

# Run tests
make test
```

## Controls

- **WASD** or **Arrow Keys**: Move player
- **Q**: Quit game
- **R**: Restart game
- **ESC**: Exit

## Project Structure

```
so_long/
├── src/           # Source code
├── inc/           # Header files
├── tests/         # Test maps
├── sprites/       # Game sprites
├── Makefile       # Build configuration
└── README.md      # This file
```

## Available Maps

The project includes 30+ test maps:
- `classic.ber` - Classic Pac-Man layout
- `island.ber` - Island-themed map
- `run.ber` - Speed challenge map
- `multipac.ber` - Multiple players map
- And many more in `tests/other-maps/`

## Technical Details

- **Graphics**: minilibx library for rendering
- **Animation**: Frame-based animation system
- **AI**: Euclidean distance-based pathfinding for ghosts
- **Memory**: Manual memory management with proper cleanup
- **Cross-Platform**: Conditional compilation for macOS/Linux

## Development

### Building from Source

```bash
# Clean build
make fclean && make

# Debug build
make clean && make CFLAGS="-g -Wall -Wextra -Werror"
```

### Code Style

The project follows 42 coding standards:
- No more than 25 lines per function
- No more than 4 parameters per function
- No more than 5 functions per file
- Proper indentation and naming conventions

## License

This project is part of the 42 curriculum and follows their guidelines.

## Contributing

This is an educational project. Feel free to study the code and learn from it, but please respect academic integrity guidelines.