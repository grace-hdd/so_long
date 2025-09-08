# Simple Makefile for so_long project
# A 2D Pac-Man style game using minilibx

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

# Project name
NAME = so_long
TARGET = $(BIN_DIR)/$(NAME)

# Source files
SOURCES = main.c map.c player.c check.c game_mac.c sprites.c \
          utils.c anim.c render_mac.c playerlist.c \
          ghosts.c pacman.c chase.c legal.c \
          score.c load_dir.c anim_dir.c

# Object files
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Create the executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete!"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Create necessary directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Clean object files
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	@echo "Cleaning executable..."
	@rm -rf $(BIN_DIR)

# Rebuild everything
re: fclean all

# Run the game with a test map
test: $(TARGET)
	@echo "Running game with test map..."
	./$(TARGET) tests/test.ber

# Run with different maps
play: $(TARGET)
	@echo "Running with multiple maps..."
	./$(TARGET) tests/classic.ber
	./$(TARGET) tests/island.ber
	./$(TARGET) tests/run.ber

# Install dependencies (for macOS)
install:
	@echo "Installing minilibx for macOS..."
	@echo "Please install XQuartz first: brew install --cask xquartz"
	@echo "Then download minilibx from 42 intranet"

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build the project"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove all generated files"
	@echo "  re      - Rebuild everything"
	@echo "  test    - Run with test map"
	@echo "  play    - Run with multiple maps"
	@echo "  install - Show installation instructions"
	@echo "  help    - Show this help"

.PHONY: all clean fclean re test play install help