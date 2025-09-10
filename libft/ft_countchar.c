#include "libft.h"

int ft_countchar(const char *s, char c)
{
    int count = 0;
    
    while (*s)
    {
        if (*s == c)
            count++;
        s++;
    }
    
    return (count);
}
