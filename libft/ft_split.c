#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **result;
    int word_count = 0;
    int i = 0;
    int start = 0;
    
    if (!s)
        return (NULL);
    
    // Count words
    while (s[i])
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
            word_count++;
        i++;
    }
    
    result = ft_malloc(sizeof(char *) * (word_count + 1));
    result[word_count] = NULL;
    
    i = 0;
    word_count = 0;
    while (s[i])
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
            start = i;
        if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
        {
            result[word_count] = ft_substr(s, start, i - start + 1);
            word_count++;
        }
        i++;
    }
    
    return (result);
}
