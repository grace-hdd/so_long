# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 00:00:00 by user              #+#    #+#              #
#    Updated: 2025/01/05 00:00:00 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes -I libft/includes -I /usr/include
MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRCDIR = src
OBJDIR = obj

SOURCES = main.c \
		  init_game.c \
		  parse_map.c \
		  game_logic.c \
		  render.c \
		  validate_map.c \
		  flood_fill.c \
		  utils.c \
		  get_next_line.c \
		  ft_split.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(MLX_FLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
