#include "game.h"

void init_game(Game *game) {
    game->player_x = 0;
    game->player_y = 0;
    game->score = 0;
    game->is_running = true;
}

void handle_input(Game *game, char input) {
    if (input == 'w') {
        game->player_y--;
    } else if (input == 's') {
        game->player_y++;
    } else if (input == 'a') {
        game->player_x--;
    } else if (input == 'd') {
        game->player_x++;
    } else if (input == 'q') {
        game->is_running = false;
    }
}

void update_game(Game *game) {
    // Update game state logic here
}

void cleanup_game(Game *game) {
    // Free resources and cleanup
}