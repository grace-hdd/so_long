#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

void load_textures(t_game *game)
{
	int width;
	int height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Walls/wall.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, 
		"textures/black.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, 
		"textures/Other/Pacdots/pacdot_food.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, 
		"textures/exit.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, 
		"textures/Pac-Man/pac_closed.xpm", &width, &height);
	game->img_ghost = mlx_xpm_file_to_image(game->mlx, 
		"textures/Ghosts/B/ghost_down1.xpm", &width, &height);
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
