# So Long

A 2D game project for 42 School using the MiniLibX graphics library.

## Project Structure

```
so_long/
├── src/                    # Source files
│   ├── main.c             # Main program entry point
│   ├── init_game.c        # Game initialization and cleanup
│   ├── parse_map.c        # Map file parsing
│   ├── game_logic.c       # Game mechanics and player movement
│   ├── render.c           # Rendering functions
│   ├── validate_map.c     # Map validation functions
│   ├── flood_fill.c       # Path validation algorithm
│   ├── utils.c            # Utility functions
│   ├── get_next_line.c    # Line reading function
│   └── ft_split.c         # String splitting function
├── includes/               # Header files
│   └── so_long.h          # Main header file
├── maps/                   # Map files (.ber format)
│   ├── valid.ber          # Sample valid map
│   ├── map1.ber           # Empty template map
│   ├── map2.ber           # Empty template map
│   └── sample.ber         # Empty template map
├── textures/               # Game textures (XPM format)
│   ├── wall.xpm           # Wall texture
│   ├── floor.xpm          # Floor texture
│   ├── player.xpm         # Player texture
│   ├── collectible.xpm    # Collectible texture
│   └── exit.xpm           # Exit texture
├── libft/                  # Libft library (placeholder)
└── Makefile               # Build configuration
```

## Game Elements

- **P**: Player starting position (exactly 1 required)
- **C**: Collectibles (at least 1 required)
- **E**: Exit (exactly 1 required)
- **1**: Walls
- **0**: Empty spaces

## Map Requirements

1. Map must be rectangular
2. Map must be surrounded by walls (1)
3. Must contain exactly one player (P)
4. Must contain at least one collectible (C)
5. Must contain exactly one exit (E)
6. All collectibles must be reachable from the player position
7. Exit must be reachable from the player position

## Controls

- **W/↑**: Move up
- **S/↓**: Move down
- **A/←**: Move left
- **D/→**: Move right
- **ESC**: Exit game

## Build Instructions

```bash
make
```

## Usage

```bash
./so_long maps/valid.ber
```

## Notes

- This project follows 42 School norminette coding standards
- All files include proper 42 headers
- Memory management is handled properly
- Error handling is implemented throughout
- The project uses MiniLibX for graphics rendering

## To Do

- Add actual texture images (currently placeholder XPM files)
- Add more diverse map examples
- Implement libft if needed
- Test on different systems
