/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 20:09:33 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/21 21:05:42 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t c;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[i]);
	while (haystack[i] != '\0')
	{
		c = 0;
		while (haystack[i + c] == needle[c] && needle[c] != '\0')
			c++;
		if (needle[c] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
