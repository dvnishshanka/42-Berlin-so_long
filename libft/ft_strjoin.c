/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:02:33 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 16:30:20 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1: The prefix string.
s2: The suffix string.

Return: The new string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	str_len;

	i = 0;
	j = 0;
	if ((!s1) || (!s2))
		return (0);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
