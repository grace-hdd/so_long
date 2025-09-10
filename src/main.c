#include "pacman.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		write(2, "Usage: ./pacman map.ber\n", 24);
		return (1);
	}
	memset(&g, 0, sizeof(t_game));
	if (!load_map(&g, argv[1]) || !validate_map(&g) || !map_has_valid_path(&g))
	{
		write(2, "Error\nInvalid map\n", 18);
		return (1);
	}
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
