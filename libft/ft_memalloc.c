/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:23:01 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/31 11:47:31 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	p = (void*)malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
