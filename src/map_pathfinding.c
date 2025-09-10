#include "include/map.h"
#include "include/utils.h"
#include "include/game.h"
#include <stdlib.h>

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

static int **allocate_visited_array(t_map *map)
{
	int **visited;
	int i;
	int j;

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
	return (visited);
}

static void free_visited_array(int **visited, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void validate_path_results(t_map *map, int found_collectibles, 
	int found_exits)
{
	if (found_collectibles != map->collectibles)
		error_exit("Not all collectibles are reachable");
	if (found_exits != map->exits)
		error_exit("Exit is not reachable");
}

int check_path(t_map *map, int start_x, int start_y)
{
	int **visited;
	int found_collectibles;
	int found_exits;

	visited = allocate_visited_array(map);
	found_collectibles = 0;
	found_exits = 0;
	dfs_flood_fill(map, start_x, start_y, visited, 
		&found_collectibles, &found_exits);
	free_visited_array(visited, map->height);
	validate_path_results(map, found_collectibles, found_exits);
	return (1);
}
