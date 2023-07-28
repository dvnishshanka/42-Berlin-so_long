/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:38:24 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/28 20:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx.h"

// Libraries
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdio.h>
# include <string.h>

// Map error codes
# define ERR_COL_SIZE 1
# define INVALID_CHAR 2
# define INVALID_WALL 3

typedef struct s_map
{
	int	coins;
	int	exit_nos;
	int	players;
	int	no_of_rows;
	int	row_size;
	int	error_flag;
}	t_map;

// error.c
void	print_error(char *msg);
void	free_map(char ***map, int i);

// validate_map.c and validate_map_utils.c
void	validate_map(char *map_name, t_map *map);
bool	check_map_data(char	*row, t_map *map, int row_no);
int		find_row_size(char	*str);

// save_map.c
void	save_map(char ***game, t_map map, char *map_name);
#endif
