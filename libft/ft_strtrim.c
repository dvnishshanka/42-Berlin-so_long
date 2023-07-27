/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:59:17 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 15:37:50 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1: The string to be trimmed.
set: The reference set of characters to trim.

Return: The trimmed string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in 'set' removed
from the beginning and the end of the string.
*/

static int	is_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	int				end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set) == 1)
		start ++;
	if (s1[0] == '\0')
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	while (s1[end] && is_in_set(s1[end], set) == 1 && end >= 0)
		end --;
	str = ft_substr(s1, start, end + 1 - start);
	if (!str)
		return (0);
	return (str);
}
