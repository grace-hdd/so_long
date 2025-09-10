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

void load_sprites(t_game *game)
{
	load_textures(game);
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
