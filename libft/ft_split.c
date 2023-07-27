/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:17:48 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/14 22:08:20 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string to be split.
c: The delimiter character.

Return: The array of new strings resulting from the split.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

// Counts the no of array elements
static size_t	count_substr(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == 0))
			count ++;
		i++;
	}
	return (count);
}

// Free the memory if array memory allocation fails
static char	**ft_free(char **arr, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
	return (0);
}

static char	**sep_words(char const *s, char sep, char **arr)
{
	size_t	start;
	size_t	i;
	size_t	word;

	start = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == sep)
		{
			start = i + 1;
		}
		else if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == 0))
		{
			arr[word] = ft_substr(s, start, i - start + 1);
			if (!arr[word])
				return (ft_free(arr, word));
			word++;
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	no_elements;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	no_elements = count_substr(s, c);
	arr = (char **)malloc(sizeof(char *) * (no_elements + 1));
	if (!arr)
		return (0);
	arr[no_elements] = 0;
	if (no_elements > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		return (sep_words(&s[i], c, arr));
	}
	return (arr);
}
