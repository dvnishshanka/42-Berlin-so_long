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

static	void	chk_invalid_char(char c, t_map *map)
{
	if (c != '1' && c != 'C' && c != 'P'
		&& c != '0' && c != 'E' && c != 'W' && (!map->error_flag))
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
		chk_invalid_char(row[i], map);
		if (row[i] != '1' && (is_line_end(row[i + 1]) || row_no == 1))
			map->error_flag = INVALID_WALL;
		if (row[i] == 'P')
		{
			map->player_pos[0] = row_no - 1;
			map->player_pos[1] = i;
			map->players ++;
		}
		if (row[i] == 'E')
			map->exit_nos ++;
		else if (row[i] == 'C')
			map->coins ++;
		i ++;
	}
	return (is_wall);
}

void	set_row_size(char	*str, t_map *map)
{
	int	str_len;

	str_len = 0;
	while (!is_line_end(*str))
	{
		str_len ++;
		str ++;
	}
	if ((str_len == 0 || (map->row_size != 0
					&& str_len != map->row_size)) && map->error_flag == 0)
		map->error_flag = ERR_COL_SIZE;
	if (map->row_size == 0 && map->error_flag == 0)
		map->row_size = str_len;
}
