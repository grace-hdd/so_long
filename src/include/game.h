#ifndef GAME_H
#define GAME_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TILE_SIZE 32
#define WALL '1'
#define EMPTY '0'
#define COLLECTIBLE 'C'
#define POWER_PELLET 'P'
#define EXIT 'E'
#define PLAYER 'M'
#define GHOST 'G'

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define STOP 4

#define CHASE 0
#define SCATTER 1
#define FRIGHTENED 2
#define EATEN 3

typedef struct s_vector {
    int x;
    int y;
} t_vector;

typedef struct s_sprite {
    void *img;
    int width;
    int height;
} t_sprite;

typedef struct s_animation {
    t_sprite *frames;
    int frame_count;
    int current_frame;
    int frame_delay;
    int frame_timer;
} t_animation;

typedef struct s_ghost {
    t_vector pos;
    t_vector target;
    int direction;
    int state;
    int state_timer;
    t_animation anim_up;
    t_animation anim_down;
    t_animation anim_left;
    t_animation anim_right;
    t_animation anim_frightened;
    t_animation anim_eaten;
    char color;
} t_ghost;

typedef struct s_pacman {
    t_vector pos;
    int direction;
    int next_direction;
    int lives;
    int score;
    int dots_eaten;
    int power_pellets_eaten;
    int power_mode;
    int power_timer;
    t_animation anim_up;
    t_animation anim_down;
    t_animation anim_left;
    t_animation anim_right;
} t_pacman;

typedef struct s_map {
    char **data;
    int width;
    int height;
    int collectibles;
    int power_pellets;
    int exits;
    int players;
    int ghosts;
} t_map;

typedef struct s_game {
    void *mlx;
    void *win;
    t_map *map;
    t_pacman *pacman;
    t_ghost *ghosts;
    int ghost_count;
    int width;
    int height;
    int running;
    int game_over;
    int level;
    int frame_count;
    
    // Sprites
    t_sprite wall_sprite;
    t_sprite dot_sprite;
    t_sprite power_pellet_sprite;
    t_sprite exit_sprite;
    t_sprite pacman_sprite;
    t_sprite ghost_sprites[7];
} t_game;

t_game *init_game(char *map_file);
void init_pacman_data(t_game *game);
void find_pacman_position(t_game *game);
void init_ghosts_data(t_game *game);
void init_game_state(t_game *game);
int init_mlx_window(t_game *game);
void cleanup_game(t_game *game);
int handle_key(int keycode, t_game *game);
int handle_close(t_game *game);
void move_pacman_direction(t_game *game, int direction);
void move_player(t_game *game, int direction);
void update_game(t_game *game);
void move_pacman(t_game *game);
void move_ghosts(t_game *game);
int is_valid_move(t_game *game, int x, int y);
void check_collisions(t_game *game);
void check_win_condition(t_game *game);
void load_sprites(t_game *game);
void free_sprites(t_game *game);

// Render functions
void render_game(t_game *game);
void render_map(t_game *game);
void render_pacman(t_game *game);
void render_ghosts(t_game *game);
void render_ui(t_game *game);

#endif