#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

int	main(void)
{
	void	*mlx;
	// void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
		print_error("ERROR IN ESTABLISHING CONNECTION WITH MINILIBX");
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "SO LONG");
	// mlx_loop(mlx);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}
