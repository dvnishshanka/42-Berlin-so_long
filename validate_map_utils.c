#include "so_long.h"

void	check_map_data(char	*row, t_map *map, int row_no)
{
	if (row[0] != '1')
	{
		map->error_flag = INVALID_WALL;
		return ;
	}	
	while (*row && *row != '\n' && *row != '\r')
	{
		if (*row != '1' && *row != 'C' && *row != 'P'
			&& *row != '0' && *row != 'E' && (!map->error_flag))
		{	
			map->error_flag = INVALID_CHAR;
			return;
		}
		if ( *row != '1' && (*(row + 1) == '\n' || *(row + 1) == '\r' || (!(*(row + 1))) || row_no == 1))
			map->error_flag = INVALID_WALL;
		row ++;
	}
}