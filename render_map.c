/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:14:47 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/30 17:14:47 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_vars *vars, int img_width, int img_height)
{
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "textures/brick.xpm", &img_width, &img_height);
	vars->bird = mlx_xpm_file_to_image(vars->mlx, "textures/bird.xpm", &img_width, &img_height);
	vars->cherry = mlx_xpm_file_to_image(vars->mlx, "textures/cherry-new.xpm", &img_width, &img_height);
	vars->cage = mlx_xpm_file_to_image(vars->mlx, "textures/cage.xpm", &img_width, &img_height);
	vars->grass = mlx_xpm_file_to_image(vars->mlx, "textures/grass.xpm", &img_width, &img_height);
}

void	render_map(char **game, t_vars vars, t_map map_info)
{
	int		img_width = 100;
	int		img_height = 100;
	int	i = 0;
	int j;

	while (i < map_info.no_of_rows)
	{
		j = 0;
		while (game[i][j])
		{
			if (game[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, j * img_width, i * img_height);
			else if (game[i][j] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.bird, j * img_width, i * img_height);
			else if (game[i][j] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.cherry, j * img_width, i * img_height);
			else if (game[i][j] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.cage, j * img_width, i * img_height);
			else
				mlx_put_image_to_window(vars.mlx, vars.win, vars.grass, j * img_width, i * img_height);
			
			j++;
		}
		i ++;
	}
}