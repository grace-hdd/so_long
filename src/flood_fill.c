/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_game *game, char **visited, int x, int y)
{
	int	collectibles_found;
	int	exits_found;

	collectibles_found = 0;
	exits_found = 0;
	flood_fill_recursive(game, visited, x, y, &collectibles_found, &exits_found);
	if (collectibles_found != game->map.collectibles)
		error_exit("Error: Not all collectibles are reachable");
	if (exits_found != 1)
		error_exit("Error: Exit is not reachable");
	return (0);
}

void	flood_fill_recursive(t_game *game, char **visited, int x, int y,
			int *collectibles_found, int *exits_found)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return;
	if (visited[y][x] || game->map.grid[y][x] == '1')
		return;
	visited[y][x] = 1;
	if (game->map.grid[y][x] == 'C')
		(*collectibles_found)++;
	if (game->map.grid[y][x] == 'E')
		(*exits_found)++;
	flood_fill_recursive(game, visited, x + 1, y, collectibles_found,
		exits_found);
	flood_fill_recursive(game, visited, x - 1, y, collectibles_found,
		exits_found);
	flood_fill_recursive(game, visited, x, y + 1, collectibles_found,
		exits_found);
	flood_fill_recursive(game, visited, x, y - 1, collectibles_found,
		exits_found);
}

void	free_visited_array(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
