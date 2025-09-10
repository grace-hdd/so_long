#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
int ft_countchar(const char *s, char c);
void *ft_malloc(size_t size);
void ft_free(void *ptr);
char *ft_strdup(const char *s);
int ft_isdigit(int c);
int ft_atoi(const char *str);

#endif
