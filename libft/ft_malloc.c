#include "libft.h"

void *ft_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        printf("Error\nMemory allocation failed\n");
        exit(1);
    }
    return (ptr);
}
