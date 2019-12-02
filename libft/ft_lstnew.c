/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 16:52:52 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/05 18:06:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		elem->content = NULL;
		elem->next = NULL;
	}
	else
	{
		elem->content = (void*)malloc(content_size);
		if (!elem->content)
		{
			free(elem->content);
			return (0);
		}
		elem->content = ft_memcpy((elem->content), content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
