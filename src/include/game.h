#ifndef GAME_H
#define GAME_H

typedef struct s_game {
    // Game state variables
    int player_x;
    int player_y;
    int score;
    // Add other game state variables as needed
} t_game;

void init_game(t_game *game);
void handle_input(t_game *game);
void update_game(t_game *game);
void free_game(t_game *game);

#endif // GAME_H