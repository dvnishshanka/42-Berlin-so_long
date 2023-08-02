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

static void	put_image(char **game, t_vars vars, int img_size, int *p)
{
	if (game[p[0]][p[1]] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.wall,
			p[1] * img_size, p[0] * img_size);
	else if (game[p[0]][p[1]] == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.birdl,
			p[1] * img_size, p[0] * img_size);
	else if (game[p[0]][p[1]] == 'p')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.birdr,
			p[1] * img_size, p[0] * img_size);
	else if (game[p[0]][p[1]] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.cherry,
			p[1] * img_size, p[0] * img_size);
	else if (game[p[0]][p[1]] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.cage, p[1] * img_size, p[0] * img_size);
	else if (game[p[0]][p[1]] == 'W')
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.wolf, p[1] * img_size, p[0] * img_size);
	else
		mlx_put_image_to_window(vars.mlx, vars.win,
			vars.grass, p[1] * img_size, p[0] * img_size);
}

void	render_map(char **game, t_vars vars, t_map map_info)
{
	int	p[2];

	p[0] = 0;
	while (p[0] < map_info.no_of_rows)
	{
		p[1] = 0;
		while (game[p[0]][p[1]])
		{
			put_image(game, vars, map_info.img_size, p);
			p[1]++;
		}
		p[0]++;
	}
}
