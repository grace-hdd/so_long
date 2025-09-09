#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vector {
    int x;
    int y;
} t_vector;

t_vector ft_newvector(int x, int y);
int ft_euclideandistance(t_vector a, t_vector b);

#endif