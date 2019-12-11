/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarradel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:12:14 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/11 14:06:31 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarradel(const char *s)
{
	if (*s == '\0')
		ft_memdel((void **)(s));
}
