/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddback.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 20:41:13 by mminkjan       #+#    #+#                */
/*   Updated: 2019/03/08 16:32:05 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *blst)
{
	t_list	*temp;

	temp = *alst;
	if (temp == NULL)
	{
		*alst = blst;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blst;
}
