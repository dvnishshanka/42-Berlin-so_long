/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:04:45 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/13 13:04:59 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
Return: None

Iterates the list 'lst' and applies the function
'f' on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst->next != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	(*f)(lst->content);
}
