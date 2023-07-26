#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

#include "mlx.h"

void	print_error(char *msg);
void	validate_map(char *map_name);
#endif
