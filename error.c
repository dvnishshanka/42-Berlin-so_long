/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:53:20 by dnishsha          #+#    #+#             */
/*   Updated: 2023/08/01 15:11:06 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_printf(RED "Error\n%s\n", msg);
	exit (1);
}

void	free_map(char ***map, int i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		free((*map)[count]);
		count ++;
	}
	free(*map);
	*map = NULL;
}

void	free_n_err(char ***map, int i, char *msg)
{
	free_map(map, i);
	print_error(msg);
}
