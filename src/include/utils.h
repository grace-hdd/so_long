#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

// Function prototypes
void handle_error(const char *message);
void *safe_malloc(size_t size);
void free_resources(void *ptr);

#endif // UTILS_H