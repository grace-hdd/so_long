#include "../inc/check.h"
int	error_msg_params(char *msg, char **map_str);
t_lay	create_level_info(void)
{
	t_lay	level_info;
	level_info.n_row = 0;
	level_info.n_col = 0;
	level_info.n_exit = 0;
	level_info.n_pl = 0;
	level_info.n_gh = 0;
	level_info.n_collect = 0;
	return (level_info);
}
char	**validate_arguments(int argc, char **argv, t_lay *lay)
{
	int		fd;
	if (argc != 2)
		error_msg_params("Invalid number of arguments!", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_params("File not found!", NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_msg_params("Invalid file type, use .ber!", NULL);
	return (check_map(fd, lay));
}
char	**check_map(int fd, t_lay *lay)
{
	char	*map_str;
	char	**map;
	t_err	map_err;
	map_str = NULL;
	map = NULL;
	map_err = ft_newmap_error();
	*lay = ft_newlayout();
	ft_readlayout(fd, &map_err, lay, &map_str);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg_params("Memory allocation error!", NULL);
	return (map);
}
