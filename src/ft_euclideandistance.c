#include "../inc/vector.h"
#include <math.h>

int ft_euclideandistance(t_vector a, t_vector b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (int)sqrt(dx * dx + dy * dy);
}
