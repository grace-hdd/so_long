# So Long - Quick Reference

## 🚀 Quick Start

```bash
# Build the project
make

# Run the game
./so_long maps/valid.ber

# Clean and rebuild
make re
```

## 📁 Project Structure

```
so_long/
├── src/           # Source code
├── includes/      # Headers
├── maps/          # Game maps (.ber)
├── textures/      # Graphics (.xpm)
└── Makefile       # Build config
```

## 🎮 Game Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| S / ↓ | Move Down |
| A / ← | Move Left |
| D / → | Move Right |
| ESC | Exit Game |

## 🗺️ Map Format

### Required Elements
- **P**: Player (exactly 1)
- **C**: Collectibles (at least 1)
- **E**: Exit (exactly 1)
- **1**: Walls
- **0**: Empty spaces

### Map Rules
- Must be rectangular
- Surrounded by walls (1)
- All elements reachable
- File extension: `.ber`

## 🛠️ Common Commands

### Building
```bash
make              # Build project
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Clean and rebuild
```

### Testing
```bash
# Test with different maps
./so_long maps/valid.ber
./so_long maps/map1.ber

# Test error cases
./so_long nonexistent.ber
./so_long maps/invalid.ber
```

### Code Quality
```bash
# Check norminette
norminette src/ includes/

# Check memory leaks
valgrind --leak-check=full ./so_long maps/valid.ber
```

## 🎨 Adding Content

### New Maps
1. Create `.ber` file in `maps/` directory
2. Follow map format rules
3. Test: `./so_long maps/your_map.ber`

### New Textures
1. Create 64x64 `.xpm` files
2. Replace files in `textures/` directory
3. Rebuild: `make re`

## 🐛 Common Issues

### Compilation Errors
- **Missing MiniLibX**: Install graphics library
- **Undefined references**: Check function declarations
- **Include errors**: Verify header paths

### Runtime Errors
- **Segmentation fault**: Check null pointers
- **Map not loading**: Verify file format
- **Textures not showing**: Check XPM format

### Memory Issues
- **Memory leaks**: Use valgrind to debug
- **Double free**: Check cleanup functions

## 📝 File Responsibilities

| File | Purpose |
|------|---------|
| `main.c` | Program entry point |
| `init_game.c` | Game setup & cleanup |
| `parse_map.c` | Map file reading |
| `game_logic.c` | Player movement |
| `render.c` | Graphics rendering |
| `validate_map.c` | Map validation |
| `flood_fill.c` | Path checking |
| `utils.c` | Helper functions |

## 🔧 Development Workflow

```bash
# 1. Make changes
# Edit source files

# 2. Test changes
make re
./so_long maps/valid.ber

# 3. Check code quality
norminette src/ includes/

# 4. Commit changes
git add .
git commit -m "Description of changes"
git push
```

## 📊 Testing Checklist

- [ ] Game compiles without errors
- [ ] Valid maps load correctly
- [ ] Invalid maps show proper errors
- [ ] Player movement works
- [ ] Collectibles can be picked up
- [ ] Win condition triggers
- [ ] No memory leaks
- [ ] Norminette compliance

## 🎯 Quick Tips

1. **Start small**: Test with minimal maps first
2. **Use printf**: Add debug output for troubleshooting
3. **Check returns**: Always check function return values
4. **Validate pointers**: Ensure pointers aren't null before use
5. **Test edge cases**: Empty maps, single cell maps, etc.

## 📚 Useful Resources

- [42 Norminette](https://github.com/42School/norminette)
- [MiniLibX Docs](https://github.com/42Paris/minilibx-linux)
- [C Best Practices](https://github.com/42School/norminette)

---

**Need help?** Check the full [DEVELOPMENT_GUIDE.md](DEVELOPMENT_GUIDE.md) or open a GitHub issue.
