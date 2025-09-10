#include <stdio.h>
#include "include/game.h"

int main(int argc, char **argv) {
    // Initialize the game
    if (!initialize_game(argc, argv)) {
        fprintf(stderr, "Failed to initialize the game.\n");
        return 1;
    }

    // Start the main game loop
    run_game_loop();

    // Clean up and exit
    cleanup_game();
    return 0;
}