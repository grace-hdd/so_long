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
	load_wall_texture(game, &width, &height);
	load_floor_texture(game, &width, &height);
	load_collectible_texture(game, &width, &height);
	load_exit_texture(game, &width, &height);
	load_player_texture(game, &width, &height);
	load_ghost_texture(game, &width, &height);
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
