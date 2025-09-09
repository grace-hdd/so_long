#include <fcntl.h>
#include "../inc/check.h"
#include "../inc/game.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**level_data;
	t_lay	level_info;
	level_data = validate_arguments(argc, argv, &level_info);
	start_game(level_data, level_info);
	return (0);
}
