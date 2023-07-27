/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:41 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/02 14:28:14 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 1024 if it is a alphabetic value and otherwise will return 0.

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}
