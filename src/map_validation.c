#include "include/map.h"
#include "include/utils.h"
#include "include/game.h"
#include <stdlib.h>

int validate_map_rectangular(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		if ((int)ft_strlen(map->data[y]) != map->width)
		{
			error_exit("Map must be rectangular");
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
	}
	if (map->exits != 1)
	{
		error_exit("Map must contain exactly one exit");
	}
	if (map->collectibles < 1)
	{
		error_exit("Map must contain at least one collectible");
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
			if (!ft_strchr("10CEPGOP", c))
			{
				error_exit("Map contains invalid characters");
			}
			x++;
		}
		y++;
	}
	return (1);
}

int validate_map(t_map *map)
{
	if (!validate_map_rectangular(map))
		return (0);
	if (!validate_map_borders(map))
		return (0);
	if (!validate_map_elements(map))
		return (0);
	if (!validate_map_characters(map))
		return (0);
	return (1);
}
