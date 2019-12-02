/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 17:42:29 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/04 22:33:00 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	while (s1[i] != '\0')
		i++;
	while (c < len && s2[c] != '\0')
	{
		s1[i] = s2[c];
		i++;
		c++;
	}
	s1[i] = '\0';
	return (s1);
}
