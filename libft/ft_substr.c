#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *result;
    size_t i = 0;
    
    if (!s)
        return (NULL);
    
    if (start >= ft_strlen(s))
        return (ft_malloc(1));
    
    result = ft_malloc(len + 1);
    
    while (i < len && s[start + i])
    {
        result[i] = s[start + i];
        i++;
    }
    
    result[i] = '\0';
    return (result);
}
