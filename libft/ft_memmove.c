/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:04:00 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 13:17:14 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memmove()  function  copies n bytes from memory area src to memory area
dest.  The memory areas may overlap: copying takes place as though the bytes
in  src are first copied into a temporary array that does not overlap src or
dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*src_ptr;
	char		*dest_ptr;

	i = (n - 1);
	if (!dest && !src)
		return (dest);
	src_ptr = (const char *)src;
	dest_ptr = (char *)dest;
	if (src_ptr < dest_ptr && (src_ptr + n) > dest_ptr)
	{
		while (i >= 0)
		{
			dest_ptr[i] = src_ptr[i];
			i--;
		}
	}
	else
		ft_memcpy(dest_ptr, src_ptr, n);
	return (dest);
}
