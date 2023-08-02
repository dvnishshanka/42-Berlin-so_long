/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:40:28 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/28 11:40:28 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Map description file has to end with the ".ber" extension
static void	check_file_ext(char *map_name)
{
	char	*index_ptr;

	index_ptr = ft_strrchr(map_name, '.');
	if (!index_ptr)
		print_error("Incorrect map file extension");
	if (ft_strncmp(index_ptr, ".ber", 5) != 0)
		print_error("Incorrect map file extension");
}

// Initialize the map
static void	init_map(t_map *map)
{
	map->coins = 0;
	map->exit_nos = 0;
	map->players = 0;
	map->no_of_rows = 0;
	map->row_size = 0;
	map->error_flag = 0;
	map->moves = 0;
	map->player_pos[0] = 0;
	map->player_pos[1] = 0;
	map->img_size = 64;
}

static void	map_error(t_map *map)
{
	if (map->error_flag == ERR_COL_SIZE)
		print_error("Map row size different");
	if (map->error_flag == INVALID_WALL)
		print_error("Map wall is incomplete");
	if (map->error_flag == INVALID_CHAR)
		print_error("Map consists of undefined characters");
	if (map->row_size == map->no_of_rows)
		print_error("Map is not rectangular");
	if (map->row_size < 3 || map->no_of_rows < 3
		|| ((map->row_size + map->no_of_rows) <= 7))
		print_error("Incorrect map");
	if (map->coins < 1 || map->exit_nos != 1
		|| map->players != 1)
		print_error("Incorrect map (Essential data is not included)");
}

static void	read_map(int map_fd, t_map *map)
{
	char	*line;
	int		line_length;
	bool	is_wall;

	init_map(map);
	is_wall = false;
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		is_wall = false;
		line_length = find_row_size(line);
		if ((line_length == 0 || (map->row_size != 0
						&& line_length != map->row_size)) && map->error_flag == 0)
			map->error_flag = ERR_COL_SIZE;
		if (map->row_size == 0 && map->error_flag == 0)
			map->row_size = line_length;
		map->no_of_rows++;
		if (!map->error_flag)
			is_wall = check_map_data(line, map, map->no_of_rows);
		free(line);
	}
	if (!is_wall)
		map->error_flag = INVALID_WALL;
	map_error(map);
}

void	validate_map(char *map_name, t_map *map)
{
	int	map_fd;

	check_file_ext(map_name);
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		print_error("Fail to open the file");
	read_map(map_fd, map);
	close(map_fd);
}
