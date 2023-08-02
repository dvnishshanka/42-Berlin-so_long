/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:15:35 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/29 13:15:35 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_hook_params *keypress_params, char *msg, bool victory)
{
	free_map(keypress_params->game, (keypress_params->map_info)->no_of_rows);
	if (victory)
	ft_printf(GREEN "%s\n", msg);
	else
	ft_printf(RED "%s\n", msg);
	mlx_loop_end(keypress_params->vars->mlx);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->wall);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->birdr);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->birdl);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->grass);
	mlx_destroy_image(keypress_params->vars->mlx,
		keypress_params->vars->cherry);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->cage);
	mlx_destroy_image(keypress_params->vars->mlx, keypress_params->vars->wolf);
	mlx_destroy_window(keypress_params->vars->mlx, keypress_params->vars->win);
	exit(0);
}

static int	keypress_handler(int keycode, t_hook_params *keypress_params)
{
	if (keycode == ESC_KEY)
		close_game(keypress_params, "Game closed 👋", true);
	else if (keycode == UP_KEY || keycode == UP_KEY_2)
		go_up(keypress_params);
	else if (keycode == DOWN_KEY || keycode == DOWN_KEY_2)
		go_down(keypress_params);
	else if (keycode == LEFT_KEY || keycode == LEFT_KEY_2)
		go_left(keypress_params);
	else if (keycode == RIGHT_KEY || keycode == RIGHT_KEY_2)
		go_right(keypress_params);
	return (0);
}

int	minimize_window_event(void *param)
{
	(void) param;
	return (0);
}

static void	chk_screen_size(int img_size, t_map map_info, char	***game)
{
	Display	*display;
	Screen	*screen;
	int		screen_height;
	int		screen_width;

	display = XOpenDisplay(NULL);
	screen = DefaultScreenOfDisplay(display);
	screen_height = HeightOfScreen(screen);
	screen_width = WidthOfScreen(screen);
	XCloseDisplay(display);
	if (img_size * map_info.no_of_rows > screen_height
		|| img_size * map_info.row_size > screen_width)
		free_n_err(game, map_info.no_of_rows,
			"Map is too large for the screen");
}

void	render_window(char	***game, t_map map_info)
{
	t_vars			vars;
	t_hook_params	keypress_params;
	int				img_size;

	img_size = map_info.img_size;
	chk_screen_size(img_size, map_info, game);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		free_n_err(game, map_info.no_of_rows,
			"Error in establishing connection with Minilibx");
	vars.win = mlx_new_window(vars.mlx, img_size * (map_info.row_size),
		img_size * (map_info.no_of_rows + 1), "So Long Game");
	if (!vars.win)
	{
		free(vars.mlx);
		free_n_err(game, map_info.no_of_rows, "Error in establishing connection with Minilibx");
	}
	init_images(&vars, img_size, img_size);
	keypress_params.vars = &vars;
	keypress_params.game = game;
	keypress_params.map_info = & map_info;
	mlx_hook(vars.win, KEY_PRESS, 1L << 0, keypress_handler, &keypress_params);
	render_map(*game, vars, map_info);
	mlx_loop(vars.mlx);
}
