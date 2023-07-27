/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:33:50 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/14 10:45:57 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr() function returns a pointer to the last occurrence of
the character c in the string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*occurrence;
	int		i;

	occurrence = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			occurrence = (char *)(&s[i]);
		i ++;
	}
	if (s[i] == (char)c)
		occurrence = (char *)(&s[i]);
	return (occurrence);
}
