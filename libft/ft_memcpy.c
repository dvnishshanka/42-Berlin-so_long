/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:50:09 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 13:16:31 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memcpy()  function  copies  n bytes from memory area src to memory area
// dest.  The memory areas must not overlap.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	i = 0;
	if (!dest && !src)
		return (dest);
	dest_ptr = ((char *)dest);
	src_ptr = ((const char *)src);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
