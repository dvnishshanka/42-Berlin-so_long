/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:48:55 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/14 10:46:33 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memchr()  function scans the initial n bytes of the memory area pointed
to by s for the first instance of c.  Both c and the  bytes  of  the  memory
area pointed to by s are interpreted as unsigned char.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s_ptr;

	i = 0;
	s_ptr = (const char *)s;
	while (i < n)
	{
		if (s_ptr[i] == (char)c)
			return ((void *)(&s_ptr[i]));
		i ++;
	}
	return (0);
}
