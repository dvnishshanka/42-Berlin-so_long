/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:51:22 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/05 11:21:10 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memset() function fills the first n bytes of the memory
//        area pointed to by s with the constant byte c.

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
