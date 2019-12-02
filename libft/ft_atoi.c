/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 15:29:34 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/05 18:15:04 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*ft_whitespace(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (&str[i]);
}

static size_t			ft_isstrlower(const char *str, const char *str2,
						size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && str[i] != '\0')
	{
		if (!(str[i] <= str2[i]))
			return (0);
		i++;
	}
	return (1);
}

static	size_t			ft_exceptional(const char *str, const char sign)
{
	size_t		i;

	i = 0;
	while (ft_isdigit(str[i]) == 1 && i < 19)
	{
		i++;
	}
	if (i == 19 && ft_isdigit(str[i]) == 1)
	{
		if (sign == '-')
			return (0);
		return (-1);
	}
	else if (i == 19)
	{
		if (sign == '-' && ft_isstrlower(str, "9223372036854775808", 19) == 0)
			return (0);
		if (sign != '-' && ft_isstrlower(str, "9223372036854775807", 19) == 0)
			return (-1);
	}
	return (42);
}

size_t					ft_atoi(const char *str)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	str = ft_whitespace(str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_exceptional(&str[i], str[0]) != 42)
		return (ft_exceptional(&str[i], str[0]));
	while (ft_isdigit(str[i]) == 1)
	{
		n = (str[i] - '0') + n;
		if (ft_isdigit(str[i + 1]) == 1)
			n = (n * 10);
		i++;
	}
	if (str[0] == '-')
		n = -(n);
	return (n);
}
