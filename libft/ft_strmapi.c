/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:32:56 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 16:46:41 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s: The string on which to iterate.
f: The function to apply to each character.

The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails

Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	int		s_len;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (0);
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
