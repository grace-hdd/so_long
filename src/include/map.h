#ifndef MAP_H
#define MAP_H

#include "game.h"

t_map *load_map(const char *filename);
char *read_map_file(int fd);
t_map *parse_map_data(char *map_str);
void calculate_map_dimensions(t_map *map);
void count_map_elements(t_map *map);
void free_map(t_map *map);
int validate_map(t_map *map);
int validate_map_rectangular(t_map *map);
int validate_map_borders(t_map *map);
int validate_map_elements(t_map *map);
int validate_map_characters(t_map *map);
int check_path(t_map *map, int start_x, int start_y);
void print_map(t_map *map);

#endif