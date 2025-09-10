#include "include/game.h"
#include "include/utils.h"
#include "include/map.h"
#include "include/render.h"
#include "libft/libft.h"
#include <stdio.h>

void move_player(t_game *game, int direction)
{
	int new_x;
	int new_y;

	new_x = game->pacman->pos.x;
	new_y = game->pacman->pos.y;
	
	if (direction == UP)
		new_y--;
	else if (direction == DOWN)
		new_y++;
	else if (direction == LEFT)
		new_x--;
	else if (direction == RIGHT)
		new_x++;
	
	if (is_valid_move(game, new_x, new_y))
	{
		game->map->data[game->pacman->pos.y][game->pacman->pos.x] = EMPTY;
		game->pacman->pos.x = new_x;
		game->pacman->pos.y = new_y;
		game->pacman->moves++;
		
		if (game->map->data[new_y][new_x] == COLLECTIBLE)
		{
			game->pacman->collected++;
			game->map->collectibles--;
		}
		
		if (game->map->data[new_y][new_x] == EXIT)
		{
			check_win_condition(game);
		}
		
		game->map->data[new_y][new_x] = PLAYER;
		printf("Moves: %d\n", game->pacman->moves);
		render_game(game);
	}
}

int is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->data[y][x] == WALL)
		return (0);
	return (1);
}

void check_win_condition(t_game *game)
{
	if (game->map->collectibles == 0 && 
		game->map->data[game->pacman->pos.y][game->pacman->pos.x] == EXIT)
	{
		printf("You won! Total moves: %d\n", game->pacman->moves);
		handle_close(game);
	}
}

void cleanup_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->pacman)
			free(game->pacman);
		if (game->ghosts)
			free(game->ghosts);
		free_textures(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 119 || keycode == 65362)
		move_pacman_direction(game, UP);
	else if (keycode == 115 || keycode == 65364)
		move_pacman_direction(game, DOWN);
	else if (keycode == 97 || keycode == 65361)
		move_pacman_direction(game, LEFT);
	else if (keycode == 100 || keycode == 65363)
		move_pacman_direction(game, RIGHT);
	return (0);
}
