#include "pacman.h"

static int	is_walkable(t_game *g, int x, int y)
{
	if (x < 0 || y < 0 || x >= g->map.cols || y >= g->map.rows)
		return (0);
	if (g->map.tiles[y][x] == TILE_WALL)
		return (0);
	return (1);
}

void	update_player(t_game *g)
{
	int	dx[4];
	int	dy[4];
	int	nx;
	int	ny;

	dx[0] = 0; dy[0] = -1;
	dx[1] = 1; dy[1] = 0;
	dx[2] = 0; dy[2] = 1;
	dx[3] = -1; dy[3] = 0;
	if (g->player.next_dir != DIR_NONE)
	{
		nx = g->player.x + dx[g->player.next_dir];
		ny = g->player.y + dy[g->player.next_dir];
		if (is_walkable(g, nx, ny))
			g->player.dir = g->player.next_dir;
	}
	nx = g->player.x + dx[g->player.dir];
	ny = g->player.y + dy[g->player.dir];
	if (is_walkable(g, nx, ny))
	{
		g->player.x = nx;
		g->player.y = ny;
	}
}
