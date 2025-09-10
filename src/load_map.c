#include "pacman.h"
#include <fcntl.h>
#include <stdio.h>

static t_tile	parse_tile(char c, t_game *g, int x, int y)
{
	if (c == '1')
		return (TILE_WALL);
	if (c == '0')
		return (TILE_FLOOR);
	if (c == '.')
		return (TILE_PELLET);
	if (c == 'P')
	{
		g->player.x = x;
		g->player.y = y;
		return (TILE_PLAYER_START);
	}
	return (TILE_FLOOR);
}

int	load_map(t_game *g, const char *path)
{
	FILE	*f;
	char	line[256];
	int		r;
	int		c;

	f = fopen(path, "r");
	if (!f)
		return (0);
	r = 0;
	while (fgets(line, sizeof(line), f))
	{
		g->map.cols = 0;
		c = 0;
		while (line[c] && line[c] != '\n')
		{
			g->map.tiles[r][c] = parse_tile(line[c], g, c, r);
			c++;
		}
		g->map.cols = c;
		r++;
	}
	g->map.rows = r;
	fclose(f);
	return (1);
}

int	validate_map(t_game *g)
{
	int	r;
	int	c;

	r = -1;
	while (++r < g->map.rows)
	{
		if (g->map.tiles[r][0] != TILE_WALL
			|| g->map.tiles[r][g->map.cols - 1] != TILE_WALL)
			return (0);
	}
	c = -1;
	while (++c < g->map.cols)
		if (g->map.tiles[0][c] != TILE_WALL
			|| g->map.tiles[g->map.rows - 1][c] != TILE_WALL)
			return (0);
	return (1);
}

int	map_has_valid_path(t_game *g)
{
	(void)g;
	return (1);
}
