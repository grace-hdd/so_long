# So Long - Development Guide

## Table of Contents
1. [Project Overview](#project-overview)
2. [Prerequisites](#prerequisites)
3. [Project Structure](#project-structure)
4. [Building the Project](#building-the-project)
5. [Running the Game](#running-the-game)
6. [Creating Maps](#creating-maps)
7. [Adding Textures](#adding-textures)
8. [Code Organization](#code-organization)
9. [Development Workflow](#development-workflow)
10. [Testing](#testing)
11. [Troubleshooting](#troubleshooting)
12. [Contributing](#contributing)

## Project Overview

So Long is a 2D game project for 42 School that uses the MiniLibX graphics library. The player must collect all items and reach the exit to win the game.

### Game Elements
- **P**: Player (exactly 1 required)
- **C**: Collectibles (at least 1 required)
- **E**: Exit (exactly 1 required)
- **1**: Walls
- **0**: Empty spaces

## Prerequisites

### Required Software
- **GCC compiler** (version 7.0 or higher)
- **Make** build system
- **MiniLibX library** (42's graphics library)
- **Git** (for version control)

### System Requirements
- Linux/macOS (recommended for 42 environment)
- Windows with WSL2 (alternative)
- X11 server (for graphics)

### Installing MiniLibX
```bash
# On 42 campus machines, MiniLibX is usually pre-installed
# For local development, you may need to install it manually
```

## Project Structure

```
so_long/
├── src/                    # Source code files
│   ├── main.c             # Program entry point
│   ├── init_game.c        # Game initialization & cleanup
│   ├── parse_map.c        # Map file parsing
│   ├── game_logic.c       # Player movement & game mechanics
│   ├── render.c           # Graphics rendering
│   ├── validate_map.c     # Map validation functions
│   ├── flood_fill.c       # Path validation algorithm
│   ├── utils.c            # Utility functions
│   ├── get_next_line.c    # File reading
│   └── ft_split.c         # String splitting
├── includes/               # Header files
│   └── so_long.h          # Main header with all declarations
├── maps/                   # Game maps (.ber files)
│   ├── valid.ber          # Sample valid map
│   ├── map1.ber           # Template map
│   ├── map2.ber           # Template map
│   └── sample.ber         # Template map
├── textures/               # Game textures (.xpm files)
│   ├── wall.xpm           # Wall texture
│   ├── floor.xpm          # Floor texture
│   ├── player.xpm         # Player character
│   ├── collectible.xpm    # Collectible items
│   └── exit.xpm           # Exit door
├── libft/                  # Libft library (if needed)
├── Makefile               # Build configuration
├── README.md              # Project overview
└── DEVELOPMENT_GUIDE.md   # This file
```

## Building the Project

### Basic Build
```bash
# Clean previous builds
make clean

# Build the project
make

# Clean and rebuild
make re
```

### Build Options
```bash
# Clean object files only
make clean

# Clean everything including executable
make fclean

# Rebuild from scratch
make re
```

### Expected Output
After successful build, you should see:
- `so_long` executable in the root directory
- `obj/` directory with compiled object files

## Running the Game

### Basic Usage
```bash
# Run with a map file
./so_long maps/valid.ber

# Run with different maps
./so_long maps/map1.ber
./so_long maps/sample.ber
```

### Controls
- **W** or **↑**: Move up
- **S** or **↓**: Move down
- **A** or **←**: Move left
- **D** or **→**: Move right
- **ESC**: Exit game

### Game Flow
1. Game loads the specified map
2. Player starts at position marked with 'P'
3. Collect all items marked with 'C'
4. Reach the exit marked with 'E' to win
5. Move counter is displayed in terminal

## Creating Maps

### Map File Format
- File extension: `.ber`
- Text-based format
- Each character represents a game element
- Must be rectangular
- Must be surrounded by walls

### Map Requirements
1. **Rectangular shape**: All rows must have the same length
2. **Walled perimeter**: First and last rows, first and last columns must be walls (1)
3. **Single player**: Exactly one 'P' character
4. **At least one collectible**: At least one 'C' character
5. **Single exit**: Exactly one 'E' character
6. **Valid path**: All collectibles and exit must be reachable

### Example Map Structure
```
111111111111111111111
1P0000000000000000001
100000000000000000001
100000C00000C0000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
100000000000000000001
10000000000000000000E
111111111111111111111
```

### Creating Your Own Maps
1. Create a new `.ber` file in the `maps/` directory
2. Follow the format requirements above
3. Test with: `./so_long maps/your_map.ber`

## Adding Textures

### Texture Format
- File format: `.xpm` (X PixMap)
- Size: 64x64 pixels (recommended)
- Colors: Use simple color schemes for better performance

### Texture Files Required
- `wall.xpm` - For walls (1)
- `floor.xpm` - For empty spaces (0)
- `player.xpm` - For player character (P)
- `collectible.xpm` - For collectible items (C)
- `exit.xpm` - For exit door (E)

### Creating Custom Textures
1. Create 64x64 pixel images
2. Convert to XPM format
3. Replace existing files in `textures/` directory
4. Rebuild the project: `make re`

### XPM File Structure
```c
/* XPM */
static char * texture_name_xpm[] = {
"64 64 2 1",           // width height colors chars_per_pixel
"  c #FFFFFF",         // color definitions
". c #000000",
"................................................................",  // pixel data
// ... more lines
};
```

## Code Organization

### File Responsibilities

#### Core Files
- **`main.c`**: Program entry point, argument validation
- **`init_game.c`**: Game initialization, MLX setup, cleanup
- **`parse_map.c`**: Map file reading and parsing

#### Game Logic
- **`game_logic.c`**: Player movement, game state management
- **`validate_map.c`**: Map validation (walls, elements, rectangle)
- **`flood_fill.c`**: Path validation using flood fill algorithm

#### Rendering
- **`render.c`**: Graphics rendering, texture loading
- **`utils.c`**: Utility functions (string operations, memory)

#### Parsing Utilities
- **`get_next_line.c`**: Line-by-line file reading
- **`ft_split.c`**: String splitting functionality

### Key Functions

#### Map Parsing
```c
int parse_map(t_game *game, char *map_file);
int validate_map(t_game *game);
int check_map_elements(t_game *game);
```

#### Game Logic
```c
int handle_keypress(int keycode, t_game *game);
void move_player(t_game *game, int dx, int dy);
int is_valid_move(t_game *game, int x, int y);
```

#### Rendering
```c
void render_game(t_game *game);
void render_tile(t_game *game, int x, int y);
void load_textures(t_game *game);
```

## Development Workflow

### 1. Setting Up Development Environment
```bash
# Clone the repository
git clone https://github.com/grace-hdd/so_long.git
cd so_long

# Build the project
make

# Test with sample map
./so_long maps/valid.ber
```

### 2. Making Changes
```bash
# Create a new branch for features
git checkout -b feature/new-feature

# Make your changes
# Edit source files as needed

# Test your changes
make re
./so_long maps/valid.ber

# Commit changes
git add .
git commit -m "Add new feature: description"
```

### 3. Testing Changes
```bash
# Test with different maps
./so_long maps/map1.ber
./so_long maps/sample.ber

# Test error cases
./so_long nonexistent.ber
./so_long maps/invalid.ber
```

### 4. Code Quality
```bash
# Check norminette compliance
norminette src/ includes/

# Check for memory leaks (if valgrind available)
valgrind --leak-check=full ./so_long maps/valid.ber
```

## Testing

### Unit Testing
Create test maps to verify different scenarios:

#### Valid Maps
- `maps/valid.ber` - Basic valid map
- `maps/small.ber` - Minimal valid map
- `maps/large.ber` - Large map with many collectibles

#### Invalid Maps (for error testing)
- `maps/no_player.ber` - Missing player
- `maps/multiple_players.ber` - Multiple players
- `maps/no_exit.ber` - Missing exit
- `maps/no_collectibles.ber` - No collectibles
- `maps/unreachable.ber` - Unreachable collectibles

### Test Cases
1. **Valid map execution**
2. **Invalid argument handling**
3. **File not found errors**
4. **Memory leak testing**
5. **Edge cases** (very small/large maps)

### Performance Testing
- Test with large maps (100x100+)
- Monitor memory usage
- Check frame rate performance

## Troubleshooting

### Common Issues

#### Compilation Errors
```bash
# Missing MiniLibX
# Solution: Install MiniLibX or check library path

# Missing includes
# Solution: Check #include statements in headers

# Undefined references
# Solution: Check function declarations in so_long.h
```

#### Runtime Errors
```bash
# Segmentation fault
# Solution: Check for null pointer dereferences

# Map not loading
# Solution: Verify map file format and permissions

# Textures not loading
# Solution: Check XPM file format and paths
```

#### Memory Issues
```bash
# Memory leaks
# Solution: Ensure all malloc'd memory is freed

# Double free
# Solution: Check cleanup functions for double freeing
```

### Debug Tips
1. Use `printf` statements for debugging
2. Check return values of all functions
3. Validate all pointer operations
4. Test with minimal maps first
5. Use valgrind for memory debugging

## Contributing

### Code Style
- Follow 42 norminette rules
- Use proper 42 headers
- Maintain consistent indentation
- Add meaningful comments

### Git Workflow
```bash
# Create feature branch
git checkout -b feature/description

# Make changes and commit
git add .
git commit -m "Descriptive commit message"

# Push to remote
git push origin feature/description

# Create pull request on GitHub
```

### Pull Request Guidelines
1. Clear description of changes
2. Test all functionality
3. Ensure norminette compliance
4. Update documentation if needed

## Advanced Features

### Potential Enhancements
1. **Multiple levels**: Support for multiple map files
2. **Score system**: High score tracking
3. **Animations**: Sprite animations
4. **Sound effects**: Audio feedback
5. **Menu system**: Start/game over screens
6. **Save system**: Progress saving

### Performance Optimization
1. **Texture caching**: Reuse loaded textures
2. **Efficient rendering**: Only redraw changed areas
3. **Memory management**: Optimize allocations
4. **Algorithm optimization**: Improve flood fill

## Resources

### Documentation
- [42 School Norminette](https://github.com/42School/norminette)
- [MiniLibX Documentation](https://github.com/42Paris/minilibx-linux)
- [C Programming Best Practices](https://github.com/42School/norminette)

### Useful Tools
- **Norminette**: Code style checker
- **Valgrind**: Memory debugging
- **GDB**: Debugger
- **Make**: Build system

### Community
- 42 School Slack channels
- GitHub Issues and Discussions
- Peer code reviews

---

**Happy coding! 🎮**

For questions or issues, please open a GitHub issue or contact the maintainers.
