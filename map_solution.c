/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:03:24 by marvin            #+#    #+#             */
/*   Updated: 2023/07/28 19:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	mark_access(int	row, int col, char ***game_copy, t_map map_info)
{
	if ((row - 1) > 0 && (*game_copy)[row - 1][col] == '0')
		(*game_copy)[row - 1][col] = 'X';
	if ((row + 1) < (map_info.no_of_rows - 1) && (*game_copy)[row - 1][col] == '0')
		(*game_copy)[row + 1][col] = 'X';
	if ((col - 1) > 0 && (*game_copy)[row][col - 1] == '0')
		(*game_copy)[row][col - 1] = 'X';
	if ((col + 1) < (map_info.row_size - 1) && (*game_copy)[row][col + 1] == '0')
		(*game_copy)[row][col + 1] = 'X';
	(*game_copy)[row][col] = 'x';
	return (false);
}

static bool	is_reachable(int row, int col, char **game_copy, t_map map_info)
{
	if ((row - 1) > 0 && (game_copy)[row - 1][col] == 'x')
		return (true);
	if ((row + 1) < (map_info.no_of_rows - 1) && (game_copy)[row + 1][col] == 'x')
		return (true);
	if ((col - 1) > 0 && (game_copy)[row][col - 1] == 'x')
		return (true);
	if ((col + 1) < (map_info.row_size - 1) && (game_copy)[row][col + 1] == 'x')
		return (true);
	return (false);
}

static	void	chk_reachability(char ***game_copy, t_map map_info)
{
	int		i;
	int		j;

	i = 1;
	while ((map_info.no_of_rows - 1) > i)
	{
		j = 1;
		while (j < (map_info.row_size - 1))
		{
			if (((*game_copy)[i][j] == 'C' || (*game_copy)[i][j] == 'E') && (!is_reachable(i, j, *game_copy, map_info)))
			{
				free_map(game_copy, map_info.no_of_rows);
				print_error("Map cannot be solved");
			}
			j++;
		}
		i++;
	}
	
}

static void	map_access(char ***game_copy, t_map map_info)
{
	int		i;
	int		j;
	bool	loop_ended;

	loop_ended = false;
	while (!loop_ended)
	{
		loop_ended = true;
		i = 1;
		while ((map_info.no_of_rows - 1) > i)
		{
			j = 1;
			while (j < (map_info.row_size - 1))
			{
				if ((*game_copy)[i][j] == 'X' || (*game_copy)[i][j] == 'P')
					loop_ended = mark_access(i, j, game_copy, map_info);
				j++;
			}
			i++;
		}
	}
	print(*game_copy, map_info);
}


void	chk_solution(char **game, t_map map_info)
{
	char	**game_copy;
	int		i;

	i = 0;
	game_copy = (char **)malloc(sizeof(char *) * (map_info.no_of_rows));
	if (!game_copy)
		print_error("Memory allocation failed");
	while (i < map_info.no_of_rows)
	{
		game_copy[i] = (char *)malloc(sizeof(char) * (map_info.row_size + 1));
		ft_strlcpy(game_copy[i], game[i], map_info.row_size + 1);
		if (!game_copy[i])
		{
			free_map(&game_copy, i);
			print_error("Memory allocation failed");
		}
		i ++;
	}
	map_access(&game_copy, map_info);
	chk_reachability(&game_copy, map_info);
	// print(game_copy, map_info);
	free_map(&game_copy, map_info.no_of_rows);
}