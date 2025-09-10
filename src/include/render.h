#ifndef RENDER_H
#define RENDER_H

#include "game.h"

void render_game(t_game *game);
void render_map(t_game *game);
void draw_tile(t_game *game, int x, int y, int color);
void render_player(t_game *game);
void render_ui(t_game *game);
void load_textures(t_game *game);
void free_textures(t_game *game);

#endif