#include "include/game.h"
#include "include/utils.h"
#include <stdio.h>
#include "libft/libft.h"

void move_player(t_game *game, int direction)
{
    int new_x = game->pacman->pos.x;
    int new_y = game->pacman->pos.y;
    
    if (direction == 0) new_y--;
    else if (direction == 1) new_y++;
    else if (direction == 2) new_x--;
    else if (direction == 3) new_x++;
    
    if (is_valid_move(game, new_x, new_y))
    {
        game->map->data[game->pacman->pos.y][game->pacman->pos.x] = EMPTY;
        game->pacman->pos.x = new_x;
        game->pacman->pos.y = new_y;
        game->pacman->moves++;
        
        if (game->map->data[new_y][new_x] == COLLECTIBLE)
        {
            game->pacman->collected++;
            game->map->collectibles--;
        }
        
        if (game->map->data[new_y][new_x] == EXIT)
        {
            check_win_condition(game);
        }
        
        game->map->data[new_y][new_x] = PLAYER;
        
        printf("Moves: %d\n", game->pacman->moves);
        render_game(game);
    }
}

int is_valid_move(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
        return (0);
    if (game->map->data[y][x] == WALL)
        return (0);
    return (1);
}

void check_win_condition(t_game *game)
{
    if (game->map->collectibles == 0 && 
        game->map->data[game->pacman->pos.y][game->pacman->pos.x] == EXIT)
    {
        printf("You won! Total moves: %d\n", game->pacman->moves);
        handle_close(game);
    }
}
