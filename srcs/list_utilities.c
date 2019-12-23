/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utilities.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:08:17 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/23 18:01:16 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
