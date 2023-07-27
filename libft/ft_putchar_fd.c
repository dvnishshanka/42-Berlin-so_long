/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:02:32 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 17:12:04 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
c: The character to output.
fd: The file descriptor on which to write.
Return: None

Outputs the character ’c’ to the given file
descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &(c), 1);
}
