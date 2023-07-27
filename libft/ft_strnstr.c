/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:20:13 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 15:39:04 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strnstr() function locates the	first occurrence of the	null-terminated
string little in the string big, where not more than	len characters
are searched.  Characters that appear after a '\0'	character are not
searched.

RETURN VALUES
If	little is an empty string, big is returned; if little occurs nowhere
in	big, NULL is returned; otherwise a pointer to the first	character of
the first occurrence of little is returned. */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && ((i + j) < len) && (big[i + j] == little[j]))
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (0);
}
