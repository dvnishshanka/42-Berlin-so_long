#include "so_long.h"

void	validate_map(char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		print_error("FAIL TO OPEN THE FILE");
}