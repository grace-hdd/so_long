#include "../include/so_long.h"

static t_dir	key_to_dir(int key)
{
	if (key == KEY_W)
		return (DIR_UP);
	if (key == KEY_S)
		return (DIR_DOWN);
	if (key == KEY_A)
		return (DIR_LEFT);
	if (key == KEY_D)
		return (DIR_RIGHT);
	return (DIR_NONE);
}

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		exit(0);
	g->player.next_dir = key_to_dir(key);
	return (0);
}
