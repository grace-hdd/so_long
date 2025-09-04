/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_player(game);
}

void	render_tile(t_game *game, int x, int y)
{
	void	*img;
	int		pixel_x;
	int		pixel_y;

	pixel_x = x * 64;
	pixel_y = y * 64;
	if (game->map.grid[y][x] == '1')
		img = game->wall_img;
	else if (game->map.grid[y][x] == '0')
		img = game->floor_img;
	else if (game->map.grid[y][x] == 'C')
		img = game->collectible_img;
	else if (game->map.grid[y][x] == 'E')
		img = game->exit_img;
	else
		img = game->floor_img;
	mlx_put_image_to_window(game->mlx, game->win, img, pixel_x, pixel_y);
}

void	render_player(t_game *game)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = game->player.x * 64;
	pixel_y = game->player.y * 64;
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		pixel_x, pixel_y);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
		&width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
		&width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
		"textures/collectible.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
		&width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
		&width, &height);
	if (!game->wall_img || !game->floor_img || !game->collectible_img
		|| !game->exit_img || !game->player_img)
		error_exit("Error: Failed to load textures");
}
