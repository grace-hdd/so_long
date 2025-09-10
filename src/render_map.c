#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

void render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	render_player(game);
	render_ui(game);
}

void render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			draw_tile(game, x, y, game->map->data[y][x]);
			x++;
		}
		y++;
	}
}

void draw_tile(t_game *game, int x, int y, char tile_type)
{
	void *tile_img;

	tile_img = game->img_floor;
	if (tile_type == WALL)
		tile_img = game->img_wall;
	else if (tile_type == COLLECTIBLE)
		tile_img = game->img_collectible;
	else if (tile_type == EXIT)
		tile_img = game->img_exit;
	else if (tile_type == PLAYER)
		tile_img = game->img_player;
	else if (tile_type == GHOST)
		tile_img = game->img_ghost;
	mlx_put_image_to_window(game->mlx, game->win, tile_img, 
		x * TILE_SIZE, y * TILE_SIZE);
}

void render_player(t_game *game)
{
	draw_tile(game, game->pacman->pos.x, game->pacman->pos.y, PLAYER);
}

void render_ui(t_game *game)
{
	char moves_str[50];
	char collect_str[50];

	sprintf(moves_str, "Moves: %d", game->pacman->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, moves_str);
	sprintf(collect_str, "Collectibles: %d", game->map->collectibles);
	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, collect_str);
}
