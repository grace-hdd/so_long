#include "render.h"
#include "game.h"
#include "map.h"
#include <mlx.h>

void render_background(void *mlx_ptr, void *win_ptr, int width, int height)
{
    // Code to render the background
    mlx_clear_window(mlx_ptr, win_ptr);
}

void render_player(void *mlx_ptr, void *win_ptr, Player player)
{
    // Code to render the player on the screen
    mlx_put_image_to_window(mlx_ptr, win_ptr, player.image, player.x, player.y);
}

void render_map(void *mlx_ptr, void *win_ptr, GameMap map)
{
    // Code to render the game map
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            if (map.tiles[y][x] == '1') // Example for wall
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, map.wall_image, x * TILE_SIZE, y * TILE_SIZE);
            }
            // Add more conditions for other tile types
        }
    }
}

void render(GameState *game_state)
{
    render_background(game_state->mlx_ptr, game_state->win_ptr, game_state->width, game_state->height);
    render_map(game_state->mlx_ptr, game_state->win_ptr, game_state->map);
    render_player(game_state->mlx_ptr, game_state->win_ptr, game_state->player);
}