#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "mlx.h"

// Libraries
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#include <stdio.h>
#include <string.h>

# define ERR_COL_SIZE 1
# define INVALID_CHAR 2
# define INVALID_WALL 3

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position
typedef struct s_map
{
	int	coins;
	int exit_nos;
	int players;
	int no_of_rows;
	int no_of_cols;
	int error_flag;
}	t_map;


void	print_error(char *msg);
void	validate_map(char *map_name, t_map *map);
void	check_map_data(char	*row, t_map *map, int row_no);
#endif
