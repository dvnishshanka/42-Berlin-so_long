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

static void	print_won(t_hook_params *params)
{
	ft_printf(PURPLE "You won by %d moves 😊\n", (*(params->map_info)).moves);
	close_game(params, "Congratulations!! 🎉");
}

void	go_up(t_hook_params *params)
{
	int	x;
	int	y;

	x = (params->map_info)->player_pos[0];
	y = (params->map_info)->player_pos[1];
	if ((x - 1 > 0)
		&& (((*(params->game))[x - 1][y] == '0')
	|| ((*(params->game))[x - 1][y] == 'C')))
	{
		if ((*(params->game))[x - 1][y] == 'C')
			(*(params->map_info)).coins --;
		(*(params->game))[x - 1][y] = 'P';
		(*(params->game))[x][y] = '0';
		(*(params->map_info)).player_pos[0] = x - 1;
		(*(params->map_info)).moves ++;
		ft_printf(PURPLE "Move %d\n", (*(params->map_info)).moves);
		render_map(*(params->game), *(params->vars), *(params->map_info));
	}
	else if ((*(params->game))[x - 1][y] == 'E'
	&& (*(params->map_info)).coins == 0)
	{
		(*(params->map_info)).moves ++;
		print_won(params);
	}
}

void	go_down(t_hook_params *params)
{
	int	x;
	int	y;
	int	map_rows;

	x = (params->map_info)->player_pos[0];
	y = (params->map_info)->player_pos[1];
	map_rows = params->map_info->no_of_rows - 1;
	if ((x + 1 < map_rows) && (((*(params->game))[x + 1][y] == '0')
		|| ((*(params->game))[x + 1][y] == 'C')))
	{
		if ((*(params->game))[x + 1][y] == 'C')
			(*(params->map_info)).coins --;
		(*(params->game))[x + 1][y] = 'P';
		(*(params->game))[x][y] = '0';
		(*(params->map_info)).player_pos[0] = x + 1;
		(*(params->map_info)).moves ++;
		ft_printf(PURPLE "Move %d\n", (*(params->map_info)).moves);
		render_map(*(params->game), *(params->vars), *(params->map_info));
	}
	else if ((*(params->game))[x + 1][y] == 'E'
		&& (*(params->map_info)).coins == 0)
	{
		(*(params->map_info)).moves ++;
		print_won(params);
	}
}

void	go_left(t_hook_params *params)
{
	int	x;
	int	y;

	x = (params->map_info)->player_pos[0];
	y = (params->map_info)->player_pos[1];
	if ((y > 1) && (((*(params->game))[x][y - 1] == '0')
	|| ((*(params->game))[x][y - 1] == 'C')))
	{
		if ((*(params->game))[x][y - 1] == 'C')
			(*(params->map_info)).coins --;
		(*(params->game))[x][y - 1] = 'P';
		(*(params->game))[x][y] = '0';
		(*(params->map_info)).player_pos[1] = y - 1;
		(*(params->map_info)).moves ++;
		ft_printf(PURPLE "Move %d\n", (*(params->map_info)).moves);
		render_map(*(params->game), *(params->vars), *(params->map_info));
	}
	else if ((*(params->game))[x][y - 1] == 'E'
	&& (*(params->map_info)).coins == 0)
	{
		(*(params->map_info)).moves ++;
		print_won(params);
	}
}

void	go_right(t_hook_params *params)
{
	int	x;
	int	y;
	int	row_size;

	x = (params->map_info)->player_pos[0];
	y = (params->map_info)->player_pos[1];
	row_size = params->map_info->row_size - 1;
	if (((y + 1) < row_size) && (((*(params->game))[x][y + 1] == '0')
		|| ((*(params->game))[x][y + 1] == 'C')))
	{
		if ((*(params->game))[x][y + 1] == 'C')
			(*(params->map_info)).coins --;
		(*(params->game))[x][y + 1] = 'P';
		(*(params->game))[x][y] = '0';
		(*(params->map_info)).player_pos[1] = y + 1;
		(*(params->map_info)).moves ++;
		ft_printf(PURPLE "Move %d\n", (*(params->map_info)).moves);
		render_map(*(params->game), *(params->vars), *(params->map_info));
	}
	else if ((*(params->game))[x][y + 1] == 'E'
		&& (*(params->map_info)).coins == 0)
	{
		(*(params->map_info)).moves ++;
		print_won(params);
	}
}
