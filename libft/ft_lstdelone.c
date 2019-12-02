/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 15:43:50 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/04 12:50:06 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *elem;

	elem = *alst;
	if (elem != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(elem);
		*alst = NULL;
	}
}
