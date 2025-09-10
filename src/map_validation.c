#include "include/map.h"
#include "include/utils.h"
#include "include/game.h"
#include "libft/libft.h"

int validate_map_rectangular(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		if (ft_strlen(map->data[y]) != map->width)
		{
			error_exit("Map must be rectangular");
			return (0);
		}
		y++;
	}
	return (1);
}

int validate_map_borders(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->width)
	{
		if (map->data[0][x] != WALL || 
			map->data[map->height - 1][x] != WALL)
		{
			error_exit("Map must be surrounded by walls");
			return (0);
		}
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->data[y][0] != WALL || 
			map->data[y][map->width - 1] != WALL)
		{
			error_exit("Map must be surrounded by walls");
			return (0);
		}
		y++;
	}
	return (1);
}

int validate_map_elements(t_map *map)
{
	if (map->players != 1)
	{
		error_exit("Map must contain exactly one player");
		return (0);
	}
	if (map->exits != 1)
	{
		error_exit("Map must contain exactly one exit");
		return (0);
	}
	if (map->collectibles < 1)
	{
		error_exit("Map must contain at least one collectible");
		return (0);
	}
	return (1);
}

int validate_map_characters(t_map *map)
{
	int x;
	int y;
	char c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->data[y][x];
			if (c != WALL && c != EMPTY && c != COLLECTIBLE && 
				c != EXIT && c != PLAYER && c != GHOST)
			{
				error_exit("Map contains invalid characters");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int check_path(t_map *map, int start_x, int start_y)
{
	return (1);
}
