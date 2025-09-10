#include "libft.h"

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
		str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
        i++;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
}
