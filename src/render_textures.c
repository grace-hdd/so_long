#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

void load_sprites(t_game *game)
{
	load_textures(game);
}

void load_textures(t_game *game)
{
	int width;
	int height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Walls/wall.xpm", &width, &height);
	if (!game->img_wall)
		error_exit("Failed to load wall texture");
	game->img_floor = mlx_xpm_file_to_image(game->mlx, 
		"textures/black.xpm", &width, &height);
	if (!game->img_floor)
		error_exit("Failed to load floor texture");
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Pacdots/pacdot_food.xpm", &width, &height);
	if (!game->img_collectible)
		error_exit("Failed to load collectible texture");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, 
		"textures/exit.xpm", &width, &height);
	if (!game->img_exit)
		error_exit("Failed to load exit texture");
	game->img_player = mlx_xpm_file_to_image(game->mlx, 
		"textures/Pac-Man/pac_closed.xpm", &width, &height);
	if (!game->img_player)
		error_exit("Failed to load player texture");
	game->img_ghost = mlx_xpm_file_to_image(game->mlx, 
		"textures/Ghosts/B/ghost_down1.xpm", &width, &height);
	if (!game->img_ghost)
		error_exit("Failed to load ghost texture");
}

void free_textures(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_ghost)
		mlx_destroy_image(game->mlx, game->img_ghost);
}
