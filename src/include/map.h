#ifndef MAP_H
#define MAP_H

typedef struct s_map {
    char **data;      // 2D array representing the map
    int width;       // Width of the map
    int height;      // Height of the map
} t_map;

t_map *load_map(const char *filename); // Function to load the map from a file
void free_map(t_map *map);              // Function to free the map memory

#endif // MAP_H