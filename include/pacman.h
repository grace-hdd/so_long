#ifndef PACMAN_H
# define PACMAN_H
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef enum e_dir {DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_NONE} t_dir;
typedef enum e_tile {TILE_WALL, TILE_FLOOR, TILE_PELLET, TILE_POWER,
	TILE_PLAYER_START, TILE_GHOST_START} t_tile;

typedef struct s_map
{
	int		rows;
	int		cols;
	t_tile	tiles[128][128];
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	t_dir	dir;
	t_dir	next_dir;
	int		score;
	int		lives;
	int		moves;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_player player;
	int		pellets_remaining;
	void	*img_wall;
	void	*img_floor;
	void	*img_pellet;
	void	*img_pacman;
}	t_game;

int		load_map(t_game *g, const char *path);
int		validate_map(t_game *g);
int		map_has_valid_path(t_game *g);
int		init_game(t_game *g);
int		game_loop(t_game *g);
int		key_press(int key, t_game *g);
void	update_player(t_game *g);
void	render(t_game *g);
void	panic(const char *msg);
#endif
