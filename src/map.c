#include "include/map.h"
#include "include/utils.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void free_map(t_map *map)
{
	if (map)
	{
		if (map->data)
		{
			int i = 0;
			while (map->data[i])
			{
				free(map->data[i]);
				i++;
			}
			free(map->data);
		}
		free(map);
	}
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

int check_path(t_map *map, int start_x, int start_y)
{
	return (1);
}

void print_map(t_map *map)
{
	int y = 0;
	while (y < map->height)
	{
		printf("%s\n", map->data[y]);
		y++;
	}
}