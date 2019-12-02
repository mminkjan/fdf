/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 19:00:18 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/31 13:18:13 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
			return (1);
	}
	return (0);
}
