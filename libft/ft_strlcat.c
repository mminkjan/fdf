/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 18:15:28 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/02 00:15:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t i;
	size_t dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	if ((dstlen + 1) <= s)
	{
		while (src[i] != '\0' && (dstlen + i + 1) < s)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		i = ft_strlen(src);
		return (dstlen + i);
	}
	i = ft_strlen(src);
	while ((i + 1) <= s && src[i] != '\0')
		i++;
	return (s + i);
}
