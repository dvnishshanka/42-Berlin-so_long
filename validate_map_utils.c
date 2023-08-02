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
		&& *row != '0' && *row != 'E' && *row != 'W' && (!map->error_flag))
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
	int		i;

	i = 0;
	is_wall = chk_is_wall(row);
	if (row[i] != '1')
		map->error_flag = INVALID_WALL;
	while (row[i] && !is_line_end(row[i]) && (!map->error_flag))
	{
		chk_invalid_char(row, map);
		if (row[i] != '1' && (is_line_end(row[i + 1])|| row_no == 1))
			map->error_flag = INVALID_WALL;
		if (row[i] == 'P')
		{
			map->player_pos[0] = row_no - 1;
			map->player_pos[1] = i;
			map->players ++;
		}
		if (row[i] == 'E')
			map->exit_nos ++;
		if (row[i] == 'C')
			map->coins ++;
		i ++;
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
