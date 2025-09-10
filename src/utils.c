#include "pacman.h"
#include <stdio.h>

void	panic(const char *msg)
{
	perror(msg);
	exit(1);
}
