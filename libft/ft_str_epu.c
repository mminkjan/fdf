/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_epu.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:41:57 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/06 15:54:45 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_str_epu_dot(int i, int e, char *str)
{
	while (i < e)
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			write(1, " ", 1);
			i++;
			while (str[i] == ' ')
				i++;
		}
		write(1, &str[i], 1);
		i++;
	}
}

static void		ft_str_epu2(int i, int e, char *str)
{
	e = (e - 1);
	if (str[e] == '.')
	{
		ft_str_epu_dot(i, (e - 3), str);
		write(1, ".", 1);
		return ;
	}
	while (i < e)
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			write(1, " ", 1);
			i++;
			while (str[i] == ' ')
				i++;
		}
		write(1, &str[i], 1);
		i++;
	}
}

void			ft_str_epu(char *str)
{
	int		s;
	int		e;

	s = 0;
	e = 0;
	while (str[s] == ' ')
		s++;
	while (str[e] != '\0')
		e++;
	e = (e - 1);
	while (str[e] == ' ')
		e--;
	e = (e + 1);
	ft_str_epu2(s, e, str);
}
