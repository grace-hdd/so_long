# So Long - Troubleshooting Guide

## 🚨 Common Issues and Solutions

### Compilation Issues

#### 1. MiniLibX Not Found
**Error:**
```
fatal error: mlx.h: No such file or directory
```

**Solutions:**
```bash
# On 42 campus machines, MiniLibX is usually pre-installed
# For local development:

# Install MiniLibX manually
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make

# Update Makefile to include correct paths
# Add to CFLAGS: -I/path/to/minilibx-linux
# Add to MLX_FLAGS: -L/path/to/minilibx-linux -lmlx -lXext -lX11
```

#### 2. Undefined Reference Errors
**Error:**
```
undefined reference to `mlx_init'
undefined reference to `mlx_new_window'
```

**Solutions:**
```bash
# Check if MiniLibX is properly linked
# Verify Makefile includes:
# -lmlx -lXext -lX11 -lm

# Ensure all source files are compiled
make clean
make re
```

#### 3. Include Path Issues
**Error:**
```
fatal error: so_long.h: No such file or directory
```

**Solutions:**
```bash
# Check Makefile includes path
# Should include: -I includes

# Verify file structure
ls -la includes/
# Should show: so_long.h
```

### Runtime Issues

#### 1. Segmentation Fault
**Symptoms:**
- Game crashes immediately
- No error message
- Program exits unexpectedly

**Debugging Steps:**
```bash
# 1. Add debug prints
printf("Debug: Reached function X\n");

# 2. Check for null pointers
if (game == NULL)
    printf("Error: game is NULL\n");

# 3. Use valgrind
valgrind --leak-check=full ./so_long maps/valid.ber
```

**Common Causes:**
- Accessing uninitialized pointers
- Array bounds violations
- Null pointer dereference
- Stack overflow

#### 2. Map Not Loading
**Error:**
```
Error: Cannot open map file
Error: Memory allocation failed
```

**Solutions:**
```bash
# Check file permissions
ls -la maps/valid.ber
chmod 644 maps/valid.ber

# Verify file exists
file maps/valid.ber

# Check file format
cat maps/valid.ber
# Should show only valid characters: 01PCE
```

#### 3. Textures Not Displaying
**Symptoms:**
- Game runs but no graphics
- Black screen
- Missing textures

**Solutions:**
```bash
# Check XPM file format
file textures/wall.xpm
# Should show: X11 pixmap

# Verify XPM syntax
head -5 textures/wall.xpm
# Should show proper XPM header

# Check file permissions
ls -la textures/
```

#### 4. Game Window Not Opening
**Error:**
```
Error: Failed to initialize game
```

**Solutions:**
```bash
# Check X11 server (Linux)
echo $DISPLAY
xhost +local:

# For WSL2 users
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0

# Check graphics drivers
glxinfo | grep "direct rendering"
```

### Memory Issues

#### 1. Memory Leaks
**Detection:**
```bash
# Use valgrind
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/valid.ber

# Look for:
# - "definitely lost" bytes
# - "indirectly lost" bytes
```

**Common Causes:**
- Forgetting to free malloc'd memory
- Not calling cleanup functions
- MLX resources not destroyed

**Solutions:**
```c
// Always free allocated memory
free(ptr);
ptr = NULL;

// Call cleanup functions
cleanup_game(game);

// Destroy MLX resources
mlx_destroy_image(mlx, img);
mlx_destroy_window(mlx, win);
```

#### 2. Double Free Errors
**Error:**
```
double free or corruption
```

**Solutions:**
```c
// Set pointers to NULL after freeing
free(ptr);
ptr = NULL;

// Check if pointer is not NULL before freeing
if (ptr != NULL)
{
    free(ptr);
    ptr = NULL;
}
```

### Map Validation Issues

#### 1. Invalid Map Format
**Error:**
```
Error: Map must be rectangular
Error: Map must be surrounded by walls
```

**Solutions:**
```bash
# Check map dimensions
wc -l maps/valid.ber
# All lines should have same length

# Check first and last lines
head -1 maps/valid.ber | grep -o '1' | wc -l
tail -1 maps/valid.ber | grep -o '1' | wc -l
# Should equal line length
```

#### 2. Missing Game Elements
**Error:**
```
Error: Map must have exactly one player
Error: Map must have at least one collectible
```

**Solutions:**
```bash
# Count elements
grep -o 'P' maps/valid.ber | wc -l  # Should be 1
grep -o 'C' maps/valid.ber | wc -l  # Should be >= 1
grep -o 'E' maps/valid.ber | wc -l  # Should be 1
```

#### 3. Unreachable Elements
**Error:**
```
Error: Not all collectibles are reachable
Error: Exit is not reachable
```

**Solutions:**
- Check if walls block the path
- Ensure there's a continuous path from P to all C and E
- Use flood fill algorithm to verify reachability

### Performance Issues

#### 1. Slow Rendering
**Symptoms:**
- Low frame rate
- Laggy movement
- High CPU usage

**Solutions:**
```c
// Only render when necessary
// Use dirty flag system
if (game->needs_redraw)
{
    render_game(game);
    game->needs_redraw = 0;
}

// Optimize texture loading
// Load textures once, reuse them
```

#### 2. High Memory Usage
**Solutions:**
```c
// Use appropriate data types
// Avoid unnecessary allocations
// Free unused resources promptly
```

### Platform-Specific Issues

#### Windows/WSL2
**Issues:**
- X11 display problems
- Graphics not working

**Solutions:**
```bash
# Install X11 server (VcXsrv recommended)
# Set DISPLAY variable
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0

# Start X11 server before running game
```

#### macOS
**Issues:**
- MiniLibX compatibility
- Graphics library conflicts

**Solutions:**
```bash
# Use macOS-specific MiniLibX
# Install XQuartz
# Update Makefile for macOS paths
```

### Debugging Techniques

#### 1. Print Debugging
```c
// Add debug prints
printf("Debug: Player at (%d, %d)\n", game->player.x, game->player.y);
printf("Debug: Map size: %dx%d\n", game->map.width, game->map.height);

// Use different log levels
#ifdef DEBUG
    printf("Debug: %s\n", message);
#endif
```

#### 2. GDB Debugging
```bash
# Compile with debug info
gcc -g -o so_long src/*.c

# Run with GDB
gdb ./so_long
(gdb) run maps/valid.ber
(gdb) bt  # Backtrace on crash
(gdb) print variable_name
```

#### 3. Valgrind Analysis
```bash
# Full memory check
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/valid.ber

# Check for specific issues
valgrind --tool=memcheck --track-origins=yes ./so_long maps/valid.ber
```

### Testing Strategies

#### 1. Unit Testing
```bash
# Test individual functions
# Create test maps for specific scenarios
# Verify function return values
```

#### 2. Integration Testing
```bash
# Test complete game flow
# Test with various map sizes
# Test error conditions
```

#### 3. Stress Testing
```bash
# Test with large maps
# Test memory usage over time
# Test rapid input handling
```

## 🆘 Getting Help

### Before Asking for Help
1. Check this troubleshooting guide
2. Search existing GitHub issues
3. Verify your setup matches requirements
4. Try the suggested solutions

### When Reporting Issues
Include:
- Operating system and version
- Compiler version
- Error messages (full output)
- Steps to reproduce
- Your code changes (if any)

### Useful Commands for Debugging
```bash
# Check system info
uname -a
gcc --version
make --version

# Check file permissions
ls -la maps/ textures/

# Check memory usage
top -p $(pgrep so_long)

# Check graphics
glxinfo | grep "direct rendering"
```

---

**Still having issues?** Open a GitHub issue with detailed information about your problem.
