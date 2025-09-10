#include "include/game.h"
#include "include/utils.h"
#include "include/map.h"


void init_pacman_data(t_game *game)
{
	game->pacman = safe_malloc(sizeof(t_pacman));
	game->pacman->lives = 3;
	game->pacman->score = 0;
	game->pacman->dots_eaten = 0;
	game->pacman->power_pellets_eaten = 0;
	game->pacman->power_mode = 0;
	game->pacman->power_timer = 0;
	game->pacman->moves = 0;
	game->pacman->collected = 0;
	game->pacman->direction = RIGHT;
	game->pacman->next_direction = RIGHT;
	find_pacman_position(game);
}

void find_pacman_position(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->data[y][x] == PLAYER)
			{
				game->pacman->pos.x = x;
				game->pacman->pos.y = y;
				return;
			}
			x++;
		}
		y++;
	}
}

void init_ghosts_data(t_game *game)
{
	int x;
	int y;
	int ghost_index;
	char ghost_colors[] = {'B', 'G', 'K', 'O', 'P', 'R', 'Y'};

	game->ghost_count = game->map->ghosts;
	game->ghosts = safe_malloc(sizeof(t_ghost) * game->ghost_count);
	ghost_index = 0;
	y = 0;
	while (y < game->map->height && ghost_index < game->ghost_count)
	{
		x = 0;
		while (x < game->map->width && ghost_index < game->ghost_count)
		{
			if (game->map->data[y][x] == GHOST)
			{
				game->ghosts[ghost_index].pos.x = x;
				game->ghosts[ghost_index].pos.y = y;
				game->ghosts[ghost_index].direction = UP;
				game->ghosts[ghost_index].state = CHASE;
				game->ghosts[ghost_index].state_timer = 0;
				game->ghosts[ghost_index].color = 
					ghost_colors[ghost_index % 7];
				ghost_index++;
			}
			x++;
		}
		y++;
	}
}

void init_game_state(t_game *game)
{
	game->width = game->map->width * TILE_SIZE;
	game->height = game->map->height * TILE_SIZE;
	game->running = 1;
	game->game_over = 0;
	game->level = 1;
	game->frame_count = 0;
}

int init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width, 
		game->height, "Pac-Man");
	if (!game->win)
		return (0);
	return (1);
}
