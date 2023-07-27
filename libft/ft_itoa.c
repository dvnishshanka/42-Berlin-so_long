/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:04:15 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/09 11:08:01 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
n: the integer to convert.
Return: The string representing the integer. NULL if the allocation fails.

Allocates (with malloc(3)) and returns a string representing the integer
received as an argument. Negative numbers must be handled.
*/

static unsigned int	ft_num_digit(long int n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len ++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*num_str;
	long int		i;
	long int		num;
	unsigned int	num_digits;

	num = (long int)n;
	num_digits = ft_num_digit(num);
	i = num_digits - 1 ;
	num_str = (char *)malloc(num_digits + 1);
	if (!num_str)
		return (0);
	if (num < 0)
	{
		num_str[0] = '-';
		num = -num;
	}
	if (num == 0)
		num_str[0] = '0';
	num_str[num_digits] = '\0';
	while (num > 0 && i >= 0)
	{
		num_str[i--] = (num % 10) + '0';
		num = (num / 10);
	}
	return (num_str);
}
