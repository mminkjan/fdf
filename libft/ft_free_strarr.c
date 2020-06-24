/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_strarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:22:41 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/07 16:24:45 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strarr(char **str_array)
{
	size_t index;

	index = 0;
	while (str_array[index])
	{
		ft_bzero(str_array[index], 1);
		free(str_array[index]);
		index++;
	}
	free(str_array);
}
