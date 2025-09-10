#include "include/game.h"
#include "include/utils.h"
#include "libft/libft.h"

t_game *init_game(char *map_file)
{
    t_game *game;
    
    game = safe_malloc(sizeof(t_game));
    game->map = load_map(map_file);
    if (!game->map)
        return (NULL);
    
    init_pacman(game);
    init_ghosts(game);
    init_window(game);
    load_sprites(game);
    
    return (game);
}

void init_pacman(t_game *game)
{
    game->pacman = safe_malloc(sizeof(t_pacman));
    game->pacman->lives = 3;
    game->pacman->score = 0;
    game->pacman->dots_eaten = 0;
    game->pacman->power_pellets_eaten = 0;
    game->pacman->power_mode = 0;
    game->pacman->power_timer = 0;
    game->pacman->direction = RIGHT;
    game->pacman->next_direction = RIGHT;
    
    find_pacman_position(game);
}

void find_pacman_position(t_game *game)
{
    for (int y = 0; y < game->map->height; y++)
    {
        for (int x = 0; x < game->map->width; x++)
        {
            if (game->map->data[y][x] == PACMAN)
            {
                game->pacman->pos.x = x;
                game->pacman->pos.y = y;
                return;
            }
        }
    }
}

void init_ghosts(t_game *game)
{
    game->ghost_count = game->map->ghosts;
    game->ghosts = safe_malloc(sizeof(t_ghost) * game->ghost_count);
    
    int ghost_index = 0;
    char ghost_colors[] = {'B', 'G', 'K', 'O', 'P', 'R', 'Y'};
    
    for (int y = 0; y < game->map->height && ghost_index < game->ghost_count; y++)
    {
        for (int x = 0; x < game->map->width && ghost_index < game->ghost_count; x++)
        {
            if (game->map->data[y][x] == GHOST)
            {
                game->ghosts[ghost_index].pos.x = x;
                game->ghosts[ghost_index].pos.y = y;
                game->ghosts[ghost_index].direction = UP;
                game->ghosts[ghost_index].state = CHASE;
                game->ghosts[ghost_index].state_timer = 0;
                game->ghosts[ghost_index].color = ghost_colors[ghost_index % 7];
                ghost_index++;
            }
        }
    }
}

void init_window(t_game *game)
{
    game->width = game->map->width * TILE_SIZE;
    game->height = game->map->height * TILE_SIZE;
    game->running = 1;
    game->game_over = 0;
    game->level = 1;
    game->frame_count = 0;
    
    game->mlx = mlx_init();
    if (!game->mlx)
        return;
    
    game->win = mlx_new_window(game->mlx, game->width, game->height, "Pac-Man");
    if (!game->win)
        return;
}
