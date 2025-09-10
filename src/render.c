#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

void render_game(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    render_map(game);
    render_player(game);
    render_ui(game);
}
