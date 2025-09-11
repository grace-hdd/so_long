#include "../include/so_long.h"

int	init_game(t_game *g)
{
	int	w;
	int	h;

	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->player.lives = 3;
	w = TILE_SIZE;
	h = TILE_SIZE;
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/Other/Walls/wall.xpm", &w, &h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "textures/Other/Walls/black.xpm", &w, &h);
	g->img_pellet = mlx_xpm_file_to_image(g->mlx, "textures/Other/Pacdots/pacdot_food.xpm", &w, &h);
	g->img_pacman = mlx_xpm_file_to_image(g->mlx, "textures/Pac-Man/pac_closed.xpm", &w, &h);
	g->win = mlx_new_window(g->mlx, g->map.cols * TILE_SIZE,
			g->map.rows * TILE_SIZE, "Pacman");
	return (1);
}

int	game_loop(t_game *g)
{
	update_player(g);
	render(g);
	return (0);
}
