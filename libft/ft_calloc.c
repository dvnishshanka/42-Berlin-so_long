/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:20:45 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 15:54:42 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function allocates memory for an array of nmemb elements
of size bytes each and returns a pointer to the allocated memory.
The memory is set to zero. If nmemb or size is 0, then  calloc()
returns either NULL, or a unique pointer value that can later be
successfully passed to free(). If the multiplication of nmemb and
size would result in integer overflow, then calloc() returns an error.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc (size * nmemb);
	if (!dest)
		return (0);
	while (i < (nmemb * size))
	{
		dest[i] = '\0';
		i ++;
	}
	return ((void *)dest);
}
