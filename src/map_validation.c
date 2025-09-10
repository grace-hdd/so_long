#include "include/map.h"
#include "include/utils.h"
#include "include/game.h"
#include "libft/libft.h"
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

static void dfs_flood_fill(t_map *map, int x, int y, int **visited, 
	int *found_collectibles, int *found_exits)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return;
	if (visited[y][x])
		return;
	if (map->data[y][x] == WALL)
		return;
	visited[y][x] = 1;
	if (map->data[y][x] == COLLECTIBLE)
		(*found_collectibles)++;
	if (map->data[y][x] == EXIT)
		(*found_exits)++;
	dfs_flood_fill(map, x + 1, y, visited, found_collectibles, found_exits);
	dfs_flood_fill(map, x - 1, y, visited, found_collectibles, found_exits);
	dfs_flood_fill(map, x, y + 1, visited, found_collectibles, found_exits);
	dfs_flood_fill(map, x, y - 1, visited, found_collectibles, found_exits);
}

int check_path(t_map *map, int start_x, int start_y)
{
	int **visited;
	int i;
	int j;
	int found_collectibles;
	int found_exits;

	visited = safe_malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		visited[i] = safe_malloc(sizeof(int) * map->width);
		j = 0;
		while (j < map->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	found_collectibles = 0;
	found_exits = 0;
	dfs_flood_fill(map, start_x, start_y, visited, 
		&found_collectibles, &found_exits);
	i = 0;
	while (i < map->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	if (found_collectibles != map->collectibles)
		error_exit("Not all collectibles are reachable");
	if (found_exits != map->exits)
		error_exit("Exit is not reachable");
	return (1);
}
