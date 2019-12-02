/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:31:35 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/07 14:44:57 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*source;
	size_t				i;

	i = 0;
	source = src;
	dest = dst;
	if (len > ((size_t)(dest) - (size_t)(source)))
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	else
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	return (dst);
}
