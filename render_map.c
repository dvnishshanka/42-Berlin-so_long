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
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/brick.xpm", &img_width, &img_height);
	vars->birdl = mlx_xpm_file_to_image(vars->mlx,
			"textures/bird-l.xpm", &img_width, &img_height);
	vars->birdr = mlx_xpm_file_to_image(vars->mlx,
		"textures/bird-r.xpm", &img_width, &img_height);
	vars->cherry = mlx_xpm_file_to_image(vars->mlx,
			"textures/cherry-new.xpm", &img_width, &img_height);
	vars->cage = mlx_xpm_file_to_image(vars->mlx,
			"textures/cage.xpm", &img_width, &img_height);
	vars->grass = mlx_xpm_file_to_image(vars->mlx,
			"textures/grass.xpm", &img_width, &img_height);
	vars->wolf = mlx_xpm_file_to_image(vars->mlx,
			"textures/wolf.xpm", &img_width, &img_height);
}

static void	put_image(char **game, t_vars vars, t_map map_info, int i, int j)
{
	if (game[i][j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.wall,
			j * map_info.img_size, i * map_info.img_size);
	else if (game[i][j] == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.birdl,
			j * map_info.img_size, i * map_info.img_size);
	else if (game[i][j] == 'p')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.birdr,
			j * map_info.img_size, i * map_info.img_size);
	else if (game[i][j] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.cherry,
			j * map_info.img_size, i * map_info.img_size);
	else if (game[i][j] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.cage, j * map_info.img_size, i * map_info.img_size);
	else if (game[i][j] == 'W')
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.wolf, j * map_info.img_size, i * map_info.img_size);
	else
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.grass, j * map_info.img_size, i * map_info.img_size);
}

void	render_map(char **game, t_vars vars, t_map map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info.no_of_rows)
	{
		j = 0;
		while (game[i][j])
		{
			put_image(game, vars, map_info, i, j);
			j++;
		}
		i ++;
	}
}
