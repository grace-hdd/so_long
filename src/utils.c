#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void *allocate_memory(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        handle_error("Memory allocation failed");
    }
    return ptr;
}

void free_memory(void *ptr) {
    free(ptr);
}