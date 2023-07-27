/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:06:10 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/14 10:44:04 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The  strchr()  function returns a pointer to the first occurrence
//        of the character c in the string s.

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i ++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (0);
}
