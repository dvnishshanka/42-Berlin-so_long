/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:39:53 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/28 11:39:53 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	chk_invalid_char(char *row, t_map *map)
{
	if (*row != '1' && *row != 'C' && *row != 'P'
		&& *row != '0' && *row != 'E' && (!map->error_flag))
	{
		map->error_flag = INVALID_CHAR;
		return ;
	}
}

bool	is_line_end(char c)
{
	if (c == '\0' || c == '\n' || c == '\r')
		return (true);
	else
		return (false);
}

static bool	chk_is_wall(char	*row)
{
	while (*row && !is_line_end(*row))
	{
		if (*row != '1')
			return (false);
		row ++;
	}
	return (true);
}

bool	check_map_data(char	*row, t_map *map, int row_no)
{
	bool	is_wall;

	is_wall = chk_is_wall(row);
	if (row[0] != '1')
		map->error_flag = INVALID_WALL;
	while (*row && !is_line_end(*row) && (!map->error_flag))
	{
		chk_invalid_char(row, map);
		if (*row != '1' && (is_line_end(*(row + 1)) || row_no == 1))
			map->error_flag = INVALID_WALL;
		if (*row == 'P')
			map->players ++;
		if (*row == 'E')
			map->exit_nos ++;
		if (*row == 'C')
			map->coins ++;
		row ++;
	}
	return (is_wall);
}

int	find_row_size(char	*str)
{
	int	str_len;

	str_len = 0;
	while (!is_line_end(*str))
	{
		str_len ++;
		str ++;
	}
	return (str_len);
}
