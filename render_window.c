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
#include <X11/Xlib.h>

int	close_game(t_hook_params *keypress_params)
{
	free_map(keypress_params->game, (keypress_params->map_info)->no_of_rows);
	ft_printf(GREEN "Game closed\n");	
	mlx_loop_end(keypress_params->vars->mlx);
	mlx_destroy_window(keypress_params->vars->mlx, keypress_params->vars->win);
	exit(0);
}

static int	keypress_handler(int keycode, t_hook_params *keypress_params)
{
	ft_printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		close_game(keypress_params);
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

int minimize_window_event(void *param)
{
    (void)param; 
    return 0;
}

void	render_window(char	***game, t_map map_info)
{
	t_vars			vars;
	t_hook_params	keypress_params;

		Display* display = XOpenDisplay(NULL);
    Screen* screen = DefaultScreenOfDisplay(display);
    int screenWidth = WidthOfScreen(screen);
    int screenHeight = HeightOfScreen(screen);
	printf("screenWidth: %d %d", screenWidth, screenHeight);
    XCloseDisplay(display);
	
	vars.mlx = mlx_init();
	if (!vars.mlx)
		free_n_err(game, map_info.no_of_rows, "Error in establishing connection with Minilibx");
	vars.win = mlx_new_window(vars.mlx, 800, 800, "So Long Game");
	if (!vars.win)
		free_n_err(game, map_info.no_of_rows, "Error in establishing connection with Minilibx");
	keypress_params.vars = &vars;
	keypress_params.game = game;
	keypress_params.map_info = &map_info;
	mlx_hook(vars.win, KEY_PRESS, 1L<<0, keypress_handler, &keypress_params);
	// mlx_hook(vars.win, CLICK_CLOSE, 0, close_game, &keypress_params);
	// mlx_hook(vars.win, 33, 0, minimize_window_event, NULL);

	render_map(*game, vars, map_info);
	mlx_loop(vars.mlx);
}