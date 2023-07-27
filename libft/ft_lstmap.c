/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:05:30 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/14 22:28:36 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete
the content of a node if needed.

Return: The new list. NULL if the allocation fails.

Iterates the list 'lst' and applies the function
'f' on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*next_node;
	t_list	*new_list;

	if (!f || !lst || !del)
		return (0);
	new_list = 0;
	while (lst)
	{
		next_node = ft_lstnew((*f)(lst->content));
		if (!next_node)
		{
			ft_lstclear (&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, next_node);
		lst = lst->next;
	}
	return (new_list);
}
