#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>

void render_map(t_game *game)
{
    for (int y = 0; y < game->map->height; y++)
    {
        for (int x = 0; x < game->map->width; x++)
        {
            int color = 0x000000;
            
            if (game->map->data[y][x] == WALL)
                color = 0xFFFFFF;
            else if (game->map->data[y][x] == COLLECTIBLE)
                color = 0xFFFF00;
            else if (game->map->data[y][x] == EXIT)
                color = 0xFF0000;
            else if (game->map->data[y][x] == PLAYER)
                color = 0x00FF00;
            else if (game->map->data[y][x] == GHOST)
                color = 0xFF00FF;
            
            draw_tile(game, x, y, color);
        }
    }
}

void draw_tile(t_game *game, int x, int y, int color)
{
    for (int py = 0; py < TILE_SIZE; py++)
    {
        for (int px = 0; px < TILE_SIZE; px++)
        {
			mlx_pixel_put(game->mlx, game->win, 
				x * TILE_SIZE + px, y * TILE_SIZE + py, color);
        }
    }
}

void render_player(t_game *game)
{
}

void render_ui(t_game *game)
{
    char moves_str[50];
    sprintf(moves_str, "Moves: %d", game->pacman->moves);
    
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, moves_str);
    
    char collect_str[50];
    sprintf(collect_str, "Collectibles: %d", game->map->collectibles);
    mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, collect_str);
}
