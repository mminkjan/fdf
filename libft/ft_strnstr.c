/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 14:27:21 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/04 22:07:13 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t c;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		c = 0;
		while ((haystack[i + c] == needle[c]) && ((i + c) < len)
		&& (needle[c] != '\0'))
			c++;
		if (needle[c] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
