#include "pacman.h"

static void	draw_tile(t_game *g, int x, int y)
{
	void	*img;

	img = g->img_floor;
	if (g->map.tiles[y][x] == TILE_WALL)
		img = g->img_wall;
	mlx_put_image_to_window(g->mlx, g->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
	if (g->map.tiles[y][x] == TILE_PELLET)
		mlx_put_image_to_window(g->mlx, g->win, g->img_pellet,
			x * TILE_SIZE + 8, y * TILE_SIZE + 8);
}

void	render(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.cols)
		{
			draw_tile(g, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img_pacman,
		g->player.x * TILE_SIZE, g->player.y * TILE_SIZE);
}
