CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

NAME    = so_long

SRC     = src/main.c src/game.c src/game_init.c src/game_logic.c src/game_events.c \
          src/map_loader.c src/map_validation.c src/map_pathfinding.c\
          src/render_map.c src/render_textures.c \
          src/error.c src/get_next_line.c \
          libft/ft_strlen.c libft/ft_strjoin.c libft/ft_split.c \
          libft/ft_substr.c libft/ft_strncmp.c libft/ft_strchr.c \
          libft/ft_strlen.c libft/ft_malloc.c libft/ft_free.c \
          libft/ft_strdup.c libft/ft_isdigit.c libft/ft_atoi.c

OBJ     = $(SRC:.c=.o)

INC     = -Isrc/include -I./minilibx-linux -Ilibft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re