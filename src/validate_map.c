/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->map.players++;
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map.grid[y][x] == 'C')
				game->map.collectibles++;
			else if (game->map.grid[y][x] == 'E')
				game->map.exits++;
			else if (game->map.grid[y][x] != '0' && game->map.grid[y][x] != '1')
				error_exit("Error: Invalid character in map");
			x++;
		}
		y++;
	}
	if (game->map.players != 1)
		error_exit("Error: Map must have exactly one player");
	if (game->map.collectibles < 1)
		error_exit("Error: Map must have at least one collectible");
	if (game->map.exits != 1)
		error_exit("Error: Map must have exactly one exit");
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y == 0 || y == game->map.height - 1 || x == 0 || x == game->map.width - 1)
			{
				if (game->map.grid[y][x] != '1')
					error_exit("Error: Map must be surrounded by walls");
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		if (ft_strlen(game->map.grid[y]) != game->map.width)
			error_exit("Error: Map must be rectangular");
		y++;
	}
	return (0);
}

int	is_valid_path(t_game *game)
{
	char	**visited;
	int		result;

	visited = create_visited_array(game);
	if (!visited)
		error_exit("Error: Memory allocation failed");
	result = flood_fill(game, visited, game->player.x, game->player.y);
	free_visited_array(visited, game->map.height);
	return (result);
}

char	**create_visited_array(t_game *game)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * game->map.height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		visited[i] = malloc(sizeof(char) * game->map.width);
		if (!visited[i])
		{
			free_visited_array(visited, i);
			return (NULL);
		}
		ft_memset(visited[i], 0, game->map.width);
		i++;
	}
	return (visited);
}
