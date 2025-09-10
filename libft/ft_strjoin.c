#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    int len1 = 0;
    int len2 = 0;
    int i = 0;
    
    if (!s1 && !s2)
        return (NULL);
    
    if (s1)
        len1 = ft_strlen(s1);
    if (s2)
        len2 = ft_strlen(s2);
    
    result = ft_malloc(len1 + len2 + 1);
    
    if (s1)
    {
        while (s1[i])
        {
            result[i] = s1[i];
            i++;
        }
    }
    
    if (s2)
    {
        int j = 0;
        while (s2[j])
        {
            result[i + j] = s2[j];
            j++;
        }
    }
    
    result[i + len2] = '\0';
    return (result);
}
