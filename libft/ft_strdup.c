#include "libft.h"

char *ft_strdup(const char *s)
{
    char *result;
    int len = ft_strlen(s);
    
    result = ft_malloc(len + 1);
    
    int i = 0;
    while (s[i])
    {
        result[i] = s[i];
        i++;
    }
    result[i] = '\0';
    
    return (result);
}
