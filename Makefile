CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

NAME = so_long
TARGET = $(BIN_DIR)/$(NAME)

SOURCES = main.c level.c character.c validation.c game_mac.c graphics.c \
          utils.c anim.c render_mac.c playerlist.c \
          enemies.c pacman.c ai.c rules.c \
          score.c load_dir.c anim_dir.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re