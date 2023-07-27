/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:58:03 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 16:19:13 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s:      The string from which to create the substring.
start:  The start index of the substring in the string ’s’.
len:    The maximum length of the substring.

Return: The substring.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a substring
from the string 's'. The substring begins at index 'start' and is of
maximum size 'len'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned int	s_length;
	unsigned int	substr_length;

	i = 0;
	if (!s)
		return (0);
	s_length = ft_strlen(s);
	if (s_length <= start)
		substr_length = 0;
	else if ((start + len) < s_length)
		substr_length = len;
	else
		substr_length = s_length - start;
	ptr = (char *)malloc(sizeof(char) * (substr_length + 1));
	if (!ptr)
		return (0);
	while (s[i] && i < substr_length)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
