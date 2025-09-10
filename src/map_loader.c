#include "include/map.h"
#include "include/utils.h"
#include "libft/libft.h"

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
    char *map_str = NULL;
    
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
