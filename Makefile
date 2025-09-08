CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

NAME = so_long
TARGET = $(BIN_DIR)/$(NAME)

SOURCES = main.c map.c player.c check.c game_mac.c sprites.c \
          utils.c anim.c render_mac.c playerlist.c \
          ghosts.c pacman.c chase.c legal.c \
          score.c load_dir.c anim_dir.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -rf $(BIN_DIR)

re: fclean all

test: $(TARGET)
	@echo "Running game with test map..."
	./$(TARGET) tests/test.ber

play: $(TARGET)
	@echo "Running with multiple maps..."
	./$(TARGET) tests/classic.ber
	./$(TARGET) tests/island.ber
	./$(TARGET) tests/run.ber

install:
	@echo "Installing minilibx for macOS..."
	@echo "Please install XQuartz first: brew install --cask xquartz"
	@echo "Then download minilibx from 42 intranet"

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