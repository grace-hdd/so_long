#include "../include/so_long.h"
#include <stdio.h>

void	panic(const char *msg)
{
	perror(msg);
	exit(1);
}
