#include "../include/so_long.h"
#include <string.h>
int	error_and_exit(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		write(2, "Usage: ./pacman map.ber\n", 24);
		return (1);
	}
	memset(&g, 0, sizeof(t_game));
    g.exit_x = -1;
    g.exit_y = -1;
	if (!load_map(&g, argv[1]))
		return (error_and_exit("Cannot load map file"));
	if (!validate_map(&g))
		return (error_and_exit("Map format invalid"));
	if (!map_has_valid_path(&g))
		return (error_and_exit("Map has no valid path"));
	if (!init_game(&g))
	{
		write(2, "Error\nInit failed\n", 19);
		return (1);
	}
	mlx_key_hook(g.win, key_press, &g);
	mlx_loop_hook(g.mlx, (int (*)(void *))game_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
