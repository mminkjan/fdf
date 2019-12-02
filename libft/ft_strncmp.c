/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 15:02:29 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/25 20:47:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (0);
	while (s1[i] == s2[i] && i < len && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i] && i == len - 1)
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
