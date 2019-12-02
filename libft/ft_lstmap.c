/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 21:25:57 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/07 14:11:54 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	head = new;
	if (new != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			new->next = f(lst);
			if (new->next == NULL)
				return (NULL);
			new = new->next;
		}
	}
	else
		return (NULL);
	return (head);
}
