/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:48:01 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 17:01:20 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string on which to iterate.
f: The function to apply to each character.
Return: None

Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		s_len;

	if (!s || !f)
		return ;
	i = 0;
	s_len = ft_strlen(s);
	while (*f && i < s_len)
	{
		f(i, &s[i]);
		i++;
	}
}
