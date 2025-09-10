#include "include/game.h"
#include "include/utils.h"
#include "include/map.h"


t_game *init_game(char *map_file)
{
	t_game *game;

	game = safe_malloc(sizeof(t_game));
	game->map = load_map(map_file);
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	init_pacman_data(game);
	init_ghosts_data(game);
	init_game_state(game);
	if (!init_mlx_window(game))
	{
		cleanup_game(game);
		return (NULL);
	}
	load_sprites(game);
	return (game);
}

