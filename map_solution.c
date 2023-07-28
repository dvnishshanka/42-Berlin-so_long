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
	print(game_copy, map_info);
	free_map(&game_copy, map_info.no_of_rows);
}