#ifndef RENDER_H
#define RENDER_H

#include "game.h"
#include "map.h"

void render_init(void);
void render_game(const GameState *game_state);
void render_cleanup(void);

#endif // RENDER_H