#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

static void load_wall_texture(t_game *game, int *width, int *height)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Walls/wall.xpm", width, height);
	if (!game->img_wall)
		error_exit("Failed to load wall texture");
}

static void load_floor_texture(t_game *game, int *width, int *height)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx, 
		"textures/black.xpm", width, height);
	if (!game->img_floor)
		error_exit("Failed to load floor texture");
}

static void load_collectible_texture(t_game *game, int *width, int *height)
{
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Pacdots/pacdot_food.xpm", width, height);
	if (!game->img_collectible)
		error_exit("Failed to load collectible texture");
}

static void load_exit_texture(t_game *game, int *width, int *height)
{
	game->img_exit = mlx_xpm_file_to_image(game->mlx, 
		"textures/exit.xpm", width, height);
	if (!game->img_exit)
		error_exit("Failed to load exit texture");
}

static void load_player_texture(t_game *game, int *width, int *height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, 
		"textures/Pac-Man/pac_closed.xpm", width, height);
	if (!game->img_player)
		error_exit("Failed to load player texture");
}

static void load_ghost_texture(t_game *game, int *width, int *height)
{
	game->img_ghost = mlx_xpm_file_to_image(game->mlx, 
		"textures/Ghosts/B/ghost_down1.xpm", width, height);
	if (!game->img_ghost)
		error_exit("Failed to load ghost texture");
}

void load_textures(t_game *game)
{
	int width;
	int height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	load_wall_texture(game, &width, &height);
	load_floor_texture(game, &width, &height);
	load_collectible_texture(game, &width, &height);
	load_exit_texture(game, &width, &height);
	load_player_texture(game, &width, &height);
	load_ghost_texture(game, &width, &height);
}
