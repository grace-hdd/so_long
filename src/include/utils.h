#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void error_exit(const char *message);
void *safe_malloc(size_t size);
char *get_next_line(int fd);

#endif