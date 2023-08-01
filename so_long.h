/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:38:24 by dnishsha          #+#    #+#             */
/*   Updated: 2023/08/01 14:37:17 by dnishsha         ###   ########.fr       */
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

// To get the screen size
# include <X11/Xlib.h>

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

# define KEY_PRESS 2
# define CLICK_CLOSE 17

// Keycodes
# define ESC_KEY 65307
# define UP_KEY 119
# define DOWN_KEY 97
# define RIGHT_KEY 100
# define LEFT_KEY 115
# define UP_KEY_2 65362
# define DOWN_KEY_2 65364
# define RIGHT_KEY_2 65363
# define LEFT_KEY_2 65361

// Colors
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define PURPLE	"\e[0;35m"

typedef struct s_map
{
	int	coins;
	int	exit_nos;
	int	players;
	int	no_of_rows;
	int	row_size;
	int	error_flag;
	int	player_pos[2];
	int	moves;
	int	img_size;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*bird;
	void	*cherry;
	void	*cage;
	void	*grass;
}	t_vars;

typedef struct s_hook_params
{
	t_vars	*vars;
	char	***game;
	t_map	*map_info;
}	t_hook_params;

// error.c
void	print_error(char *msg);
void	free_map(char ***map, int i);
void	free_n_err(char ***map, int i, char *msg);

// validate_map.c and validate_map_utils.c
void	validate_map(char *map_name, t_map *map);
bool	check_map_data(char	*row, t_map *map, int row_no);
int		find_row_size(char	*str);

// save_map.c
void	save_map(char ***game, t_map map, char *map_name);

// map_solution.c Check whether the map has a feasible solution
void	chk_solution(char **game, t_map map_info);

void	render_window(char	***game, t_map map_info);
void	render_map(char **game, t_vars vars, t_map map_info);
void	init_images(t_vars *vars, int img_width, int img_height);

void	go_up(t_hook_params *keypress_params);
void	go_down(t_hook_params *keypress_params);
void	go_left(t_hook_params *keypress_params);
void	go_right(t_hook_params *keypress_params);

int		close_game(t_hook_params *keypress_params, char *msg);

void	print(char **game, t_map map_info);
#endif
