/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:11:52 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/30 20:11:52 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_hook_params *keypress_params)
{
	int	x_pos;
	int	y_pos;

	x_pos = (keypress_params->map_info)->player_pos[0];
	y_pos = (keypress_params->map_info)->player_pos[1];
	if ((x_pos - 1 > 0) && (((*(keypress_params->game))[x_pos - 1][y_pos] == '0') || ((*(keypress_params->game))[x_pos - 1][y_pos] == 'C')))
	{
		if ((*(keypress_params->game))[x_pos - 1][y_pos] == 'C')
			(*(keypress_params->map_info)).coins --;
		(*(keypress_params->game))[x_pos - 1][y_pos] = 'P';
		(*(keypress_params->game))[x_pos][y_pos] = '0';
		(*(keypress_params->map_info)).player_pos[0] = x_pos - 1;
		ft_printf(GREEN "Moves up %d\n", (*(keypress_params->map_info)).player_pos[0]);
		(*(keypress_params->map_info)).moves ++;
		render_map(*(keypress_params->game), *(keypress_params->vars), *(keypress_params->map_info));
	}
	else if ((*(keypress_params->game))[x_pos - 1][y_pos] == 'E' && (*(keypress_params->map_info)).coins == 0)
	{	close_game(keypress_params);
		(*(keypress_params->map_info)).moves ++;
	}
}

void	go_down(t_hook_params *keypress_params)
{
	int	x_pos;
	int	y_pos;
	int	map_rows;

	x_pos = (keypress_params->map_info)->player_pos[0];
	y_pos = (keypress_params->map_info)->player_pos[1];
	map_rows = keypress_params->map_info->no_of_rows - 1;
	if ((x_pos + 1 < map_rows) && (((*(keypress_params->game))[x_pos + 1][y_pos] == '0') || ((*(keypress_params->game))[x_pos + 1][y_pos] == 'C')))
	{
		if ((*(keypress_params->game))[x_pos + 1][y_pos] == 'C')
			(*(keypress_params->map_info)).coins --;
		(*(keypress_params->game))[x_pos + 1][y_pos] = 'P';
		(*(keypress_params->game))[x_pos][y_pos] = '0';
		(*(keypress_params->map_info)).player_pos[0] = x_pos + 1;
		(*(keypress_params->map_info)).moves ++;
		render_map(*(keypress_params->game), *(keypress_params->vars), *(keypress_params->map_info));
	}
	else if ((*(keypress_params->game))[x_pos + 1][y_pos] == 'E' && (*(keypress_params->map_info)).coins == 0)
	{
		(*(keypress_params->map_info)).moves ++;
		close_game(keypress_params);
	}
}

void	go_left(t_hook_params *keypress_params)
{
	int	x_pos;
	int	y_pos;

	x_pos = (keypress_params->map_info)->player_pos[0];
	y_pos = (keypress_params->map_info)->player_pos[1];
	if ((y_pos > 1) && (((*(keypress_params->game))[x_pos][y_pos - 1] == '0') || ((*(keypress_params->game))[x_pos][y_pos - 1] == 'C')))
	{
		if ((*(keypress_params->game))[x_pos][y_pos - 1] == 'C')
			(*(keypress_params->map_info)).coins --;
		(*(keypress_params->game))[x_pos][y_pos - 1] = 'P';
		(*(keypress_params->game))[x_pos][y_pos] = '0';
		(*(keypress_params->map_info)).player_pos[1] = y_pos - 1;
		ft_printf(GREEN "Moves left %d\n", (*(keypress_params->map_info)).player_pos[1]);
		(*(keypress_params->map_info)).moves ++;
		render_map(*(keypress_params->game), *(keypress_params->vars), *(keypress_params->map_info));
	}
	else if ((*(keypress_params->game))[x_pos][y_pos - 1] == 'E' && (*(keypress_params->map_info)).coins == 0)
	{
		(*(keypress_params->map_info)).moves ++;
		close_game(keypress_params);
	}
}

void	go_right(t_hook_params *keypress_params)
{
	int	x_pos;
	int	y_pos;
	int	row_size;

	x_pos = (keypress_params->map_info)->player_pos[0];
	y_pos = (keypress_params->map_info)->player_pos[1];
	row_size = keypress_params->map_info->row_size - 1;
	if (((y_pos + 1) < row_size) && (((*(keypress_params->game))[x_pos][y_pos + 1] == '0') || ((*(keypress_params->game))[x_pos][y_pos + 1] == 'C')))
	{
		if ((*(keypress_params->game))[x_pos][y_pos + 1] == 'C')
			(*(keypress_params->map_info)).coins --;
		(*(keypress_params->game))[x_pos][y_pos + 1] = 'P';
		(*(keypress_params->game))[x_pos][y_pos] = '0';
		(*(keypress_params->map_info)).player_pos[1] = y_pos + 1;
		ft_printf(GREEN "Moves right %d\n", (*(keypress_params->map_info)).player_pos[1]);
		(*(keypress_params->map_info)).moves ++;
		render_map(*(keypress_params->game), *(keypress_params->vars), *(keypress_params->map_info));
	}
	else if ((*(keypress_params->game))[x_pos][y_pos + 1] == 'E' && (*(keypress_params->map_info)).coins == 0)
	{
		(*(keypress_params->map_info)).moves ++;
		close_game(keypress_params);
	}
}