/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 15:43:14 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/05 16:03:17 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;

	list = *alst;
	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
		free(list);
		list = (*alst);
	}
	del((*alst)->content, (*alst)->content_size);
	(*alst) = (*alst)->next;
	free(list);
	(*alst) = NULL;
}
