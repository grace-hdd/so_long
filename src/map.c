#include "map.h"
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 32

typedef struct s_map {
    char **tiles;
    int width;
    int height;
} t_map;

t_map *load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return NULL;
    }

    t_map *map = malloc(sizeof(t_map));
    if (!map) {
        perror("Failed to allocate memory for map");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", &map->width, &map->height);
    map->tiles = malloc(sizeof(char *) * map->height);
    for (int i = 0; i < map->height; i++) {
        map->tiles[i] = malloc(sizeof(char) * (map->width + 1));
        fscanf(file, "%s", map->tiles[i]);
    }

    fclose(file);
    return map;
}

void free_map(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}