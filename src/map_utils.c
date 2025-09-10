#include "include/map.h"
#include "include/utils.h"
#include "include/game.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

t_map *load_map(const char *filename)
{
	int fd;
	char *map_str;
	t_map *map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open map file");
	map_str = read_map_file(fd);
	close(fd);
	if (!map_str)
		error_exit("Map file is empty");
	map = parse_map_data(map_str);
	free(map_str);
	if (!map)
		error_exit("Failed to parse map");
	calculate_map_dimensions(map);
	count_map_elements(map);
	if (!validate_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

char *read_map_file(int fd)
{
	char *line;
	char *map_str;

	map_str = NULL;
	while ((line = get_next_line(fd)))
	{
		if (!map_str)
			map_str = ft_strjoin("", line);
		else
		{
			char *temp = ft_strjoin(map_str, line);
			free(map_str);
			map_str = temp;
		}
		free(line);
	}
	return (map_str);
}

t_map *parse_map_data(char *map_str)
{
	t_map *map;

	map = safe_malloc(sizeof(t_map));
	map->data = ft_split(map_str, '\n');
	if (!map->data)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

void calculate_map_dimensions(t_map *map)
{
	map->height = 0;
	while (map->data[map->height])
		map->height++;
	map->width = (int)ft_strlen(map->data[0]);
}

static void count_element_in_cell(t_map *map, int x, int y)
{
	if (map->data[y][x] == COLLECTIBLE)
		map->collectibles++;
	else if (map->data[y][x] == EXIT)
		map->exits++;
	else if (map->data[y][x] == PLAYER)
		map->players++;
	else if (map->data[y][x] == GHOST)
		map->ghosts++;
}

static void count_elements_in_row(t_map *map, int y)
{
	int x;

	x = 0;
	while (x < map->width)
	{
		count_element_in_cell(map, x, y);
		x++;
	}
}

void count_map_elements(t_map *map)
{
	int y;

	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;
	map->ghosts = 0;
	y = 0;
	while (y < map->height)
	{
		count_elements_in_row(map, y);
		y++;
	}
}

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

static void validate_path_results(t_map *map, int found_collectibles, int found_exits)
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

void print_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		printf("%s\n", map->data[y]);
		y++;
	}
}
