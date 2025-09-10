CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -lmlx -lX11 -lGL -lm

NAME    = so_long

SRC     = main.c level.c character.c validation.c game.c graphics.c \
          utils.c anim.c render.c playerlist.c \
          enemies.c pacman.c ai.c rules.c \
          score.c load_dir.c anim_dir.c ft_euclideandistance.c

OBJ     = $(SRC:.c=.o)

INC     = -Iinc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re