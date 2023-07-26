#include "so_long.h"

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int width, height;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 2000, 2000, "Complex Fish Window");

    // Load the custom image (assuming the image is in "fish.xpm" format)
    img = mlx_xpm_file_to_image(mlx, "coin.xpm", &width, &height);

    // Check if the image was loaded successfully
    if (img == NULL)
    {
        // Handle the error
        printf("Error loading the custom image.\n");
        return 1;
    }

    // Display the fish image on the window at position (100, 50)
    mlx_put_image_to_window(mlx, win, img, 100, 50);

    mlx_loop(mlx);
    return 0;
}













// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		print_error("INCORRECT NO OF ARGUEMENTS");
// 	validate_map(argv[1]);
// 	return (0);
// }


// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	// t_data	img;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		print_error("ERROR IN ESTABLISHING CONNECTION WITH MINILIBX");
// 	mlx_win= mlx_new_window(mlx, 1920, 1080, "SO LONG");
// 	if (!mlx_win)
// 		print_error("ERROR IN ESTABLISHING CONNECTION WITH MINILIBX");
// 	mlx_loop(mlx);
// 		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 		// 						&img.endian);
// }
