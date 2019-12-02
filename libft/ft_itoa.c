/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:08:28 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/07 13:58:10 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*nb;
	unsigned int	i;

	i = ft_countdigits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = ft_strnew(i);
	if (nb == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -(n);
		nb[0] = '-';
	}
	while (i > 1 || (i > 0 && nb[0] != '-'))
	{
		i--;
		nb[i] = ('0' + (n % 10));
		n = (n / 10);
	}
	return (nb);
}
