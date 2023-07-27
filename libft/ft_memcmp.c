/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:42:54 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 09:59:09 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memcmp()  function compares the first n bytes (each interpreted as
// unsigned char) of the memory areas s1 and s2.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	i = 0;
	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}
