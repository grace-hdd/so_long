/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open map file");
	map_content = ft_strdup("");
	if (!map_content)
		error_exit("Error: Memory allocation failed");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		temp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(temp);
		free(line);
		if (!map_content)
			error_exit("Error: Memory allocation failed");
	}
	close(fd);
	game->map.grid = ft_split(map_content, '\n');
	free(map_content);
	if (!game->map.grid)
		error_exit("Error: Memory allocation failed");
	calculate_map_dimensions(game);
	if (validate_map(game) == -1)
		return (-1);
	return (0);
}

void	calculate_map_dimensions(t_game *game)
{
	int	i;

	game->map.height = 0;
	while (game->map.grid[game->map.height])
		game->map.height++;
	if (game->map.height > 0)
		game->map.width = ft_strlen(game->map.grid[0]);
}

int	validate_map(t_game *game)
{
	if (check_map_elements(game) == -1)
		return (-1);
	if (check_map_walls(game) == -1)
		return (-1);
	if (check_map_rectangle(game) == -1)
		return (-1);
	if (is_valid_path(game) == -1)
		return (-1);
	return (0);
}
