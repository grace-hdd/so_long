#include "include/utils.h"

void error_exit(const char *message)
{
    printf("Error\n%s\n", message);
    exit(1);
}

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
        error_exit("Memory allocation failed");
    return (ptr);
}
