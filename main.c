/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:53:12 by dnishsha          #+#    #+#             */
/*   Updated: 2023/08/01 14:33:43 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(char **game, t_map map_info)
{
	int	i;

	i = 0;
	while (i < map_info.no_of_rows)
	{
		ft_printf("%s\n", game[i]);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map_info;
	char	**game;

	game = NULL;
	if (argc != 2 || (!argv[1]))
		print_error("Incorrect no of arguements");
	validate_map(argv[1], &map_info);
	save_map(&game, map_info, argv[1]);
	chk_solution(game, map_info);
	render_window(&game, map_info);
	free_map(&game, map_info.no_of_rows);
	return (0);
}
