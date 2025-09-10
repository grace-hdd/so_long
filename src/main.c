#include "include/game.h"
#include "include/utils.h"

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map.ber>");
    
    game = init_game(argv[1]);
    if (!game)
        error_exit("Failed to initialize game");
    
    render_game(game);
    
    mlx_hook(game->win, 2, 1L << 0, handle_key, game);
    mlx_hook(game->win, 17, 0, handle_close, game);
    
    mlx_loop(game->mlx);
    
    cleanup_game(game);
    return (0);
}