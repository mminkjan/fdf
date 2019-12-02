/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countdigits.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:51:58 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/07 14:33:57 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigits(int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}
