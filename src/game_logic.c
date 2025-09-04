/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}

int	handle_close(t_game *game)
{
	cleanup_game(game);
	exit(0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.moves++;
		ft_putstr("Moves: ");
		ft_putnbr(game->player.moves);
		ft_putstr("\n");
		if (game->map.grid[new_y][new_x] == 'C')
		{
			game->map.grid[new_y][new_x] = '0';
			game->map.collectibles--;
		}
		if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles == 0)
		{
			ft_putstr("You won!\n");
			handle_close(game);
		}
	}
}

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	return (1);
}

int	update_game(t_game *game)
{
	render_game(game);
	return (0);
}
