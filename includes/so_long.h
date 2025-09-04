/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "mlx.h"

# define BUFFER_SIZE 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	void		*wall_img;
	void		*floor_img;
	void		*collectible_img;
	void		*exit_img;
	void		*player_img;
}	t_game;

// Main functions
int		main(int argc, char **argv);
int		init_game(t_game *game, char *map_file);
void	cleanup_game(t_game *game);

// Map parsing
int		parse_map(t_game *game, char *map_file);
int		validate_map(t_game *game);
int		check_map_elements(t_game *game);
int		check_map_walls(t_game *game);
int		check_map_rectangle(t_game *game);
int		is_valid_path(t_game *game);
void	calculate_map_dimensions(t_game *game);

// Game logic
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	render_game(t_game *game);
int		update_game(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		is_valid_move(t_game *game, int x, int y);

// Rendering
void	render_tile(t_game *game, int x, int y);
void	render_player(t_game *game);
void	load_textures(t_game *game);

// Flood fill
int		flood_fill(t_game *game, char **visited, int x, int y);
void	flood_fill_recursive(t_game *game, char **visited, int x, int y,
			int *collectibles_found, int *exits_found);
char	**create_visited_array(t_game *game);
void	free_visited_array(char **visited, int height);

// Utility functions
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	shift_buffer(char *buffer);
int		count_words(char const *s, char c);
char	*extract_word(char const *s, char c, int word_index);
int		find_word_start(char const *s, char c, int word_index);
int		find_word_length(char const *s, char c, int start);
void	free_split(char **split, int count);

// Error handling
void	error_exit(char *message);
void	cleanup_and_exit(t_game *game, char *message);

#endif
