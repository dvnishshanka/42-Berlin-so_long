/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:38:04 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/28 20:43:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
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