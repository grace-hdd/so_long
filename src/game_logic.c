#include "include/game.h"
#include "include/utils.h"
#include "include/render.h"
#include "libft/libft.h"

void cleanup_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->pacman)
			free(game->pacman);
		if (game->ghosts)
			free(game->ghosts);
		free_textures(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game);
	}
}

int handle_key(int keycode, t_game *game)
{
    if (keycode == 65307)
        handle_close(game);
    else if (keycode == 119 || keycode == 65362)
        move_pacman_direction(game, UP);
    else if (keycode == 115 || keycode == 65364)
        move_pacman_direction(game, DOWN);
    else if (keycode == 97 || keycode == 65361)
        move_pacman_direction(game, LEFT);
    else if (keycode == 100 || keycode == 65363)
        move_pacman_direction(game, RIGHT);
    return (0);
}

int handle_close(t_game *game)
{
    cleanup_game(game);
    exit(0);
}

void move_pacman_direction(t_game *game, int direction)
{
    game->pacman->next_direction = direction;
}

void update_game(t_game *game)
{
    if (game->running)
    {
        move_pacman(game);
        move_ghosts(game);
        check_collisions(game);
        check_win_condition(game);
        render_game(game);
    }
}
