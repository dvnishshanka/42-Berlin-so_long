/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:34:40 by marvin            #+#    #+#             */
/*   Updated: 2023/07/28 19:34:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	read_map_data(int map_fd, char ***game, t_map map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		j = 0;
		line = get_next_line(map_fd);
		if (!line)
			break ;
		while (j < map.row_size)
		{
			(*game)[i][j] = line[j];
			j ++;
		}
		(*game)[i][j] = '\0';
		free(line);
		i++;
	}
}


void	save_map(char ***game, t_map map, char *map_name)
{
	int	map_fd;
	int	i;

	i = 0;
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		print_error("Fail to open the file");
	*game = (char **)malloc(sizeof(char *) * (map.no_of_rows));
	if (!(*game))
		print_error("Memory allocation failed");
	while (i < map.no_of_rows)
	{
		(*game)[i] = (char *)malloc(sizeof(char) * (map.row_size + 1));
		if (!(*game)[i])
		{
			free_map(game, i);
			print_error("Memory allocation failed");
		}
		i ++;
	}
	read_map_data(map_fd, game, map);
	close(map_fd);
}