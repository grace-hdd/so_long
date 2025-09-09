#ifndef CHECK_H
# define CHECK_H
# include <fcntl.h>
# include "../libft/libft.h"
# include "map.h"
char	**check_params(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);
char	**validate_arguments(int argc, char **argv, t_lay *level_info);
#endif
