#include "include/game.h"
#include "include/utils.h"

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
