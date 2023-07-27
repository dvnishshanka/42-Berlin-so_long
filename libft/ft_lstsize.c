/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:07:20 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/13 13:07:23 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The beginning of the list.
Return: The length of the list

Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 1;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		len ++;
		lst = lst->next;
	}
	return (len);
}
