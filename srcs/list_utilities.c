/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utilities.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:08:17 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/07 16:52:14 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdbool.h>
#include <stdio.h>

void				lst_del(t_points **points,
						void (ft_del)(void*, size_t))
{
	t_points *list;

	(void)ft_del;
	list = *points;
	while ((*points)->next_x != 0)
	{
		(*points) = (*points)->next_x;
		if (*points != NULL)
			free(*points);
		list = (*points);
	}
	(*points) = (*points)->next_x;
	if (*points != NULL)
		free(*points);
	(*points) = NULL;
}

static t_points		*iterate_list(t_points *points, int next_y)
{
	int			index;
	t_points	*temp;

	index = 0;
	temp = points;
	while (index < next_y)
	{
		temp = temp->next_x;
		index++;
	}
	temp->next_y = temp;
	return (temp);
}

void				order_list(t_fdf *fdf, t_points *points)
{
	int			x;
	int			y;

	y = 1;
	while (points != NULL && y < fdf->max_y)
	{
		x = 0;
		while (x < fdf->max_x)
		{
			points->next_y = iterate_list(points, fdf->max_x);
			points = points->next_x;
			x++;
		}
		y++;
	}
}

int					ft_isnumber(char *str, int base)
{
	size_t		index;
	size_t		digits;

	index = 0;
	digits = 0;
	while (ft_iswhitespace(str[index]))
		index++;
	if (base != 10 && ft_has_prefix(&str[index], base) == 0)
		return (0);
	if (base == 2 || base == 16)
		index += 2;
	else if (base == 8)
		index++;
	else if (base == 10 && (str[index] == '-' || str[index] == '+'))
		index++;
	while (ft_isdigit_base(str[index], base) >= 0)
	{
		index++;
		digits++;
	}
	if (str[index] == '\0' && digits)
		return (1);
	return (0);
}
