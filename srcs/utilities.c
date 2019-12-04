/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:01:31 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/04 19:55:38 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			swap_points(t_points *a, t_points *b)
{
	t_points hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

static t_points	*iterate_list(t_points *points, int next_y)
{
	int			index;
	t_points	*temp;

	temp = points;
	while (index < next_y)
	{
		temp = temp->next_x;
		index++;
	}
	temp->next_y = temp;
	return (temp);
}

void			order_list(t_fdf *fdf, t_points *points)
{
	int			x;
	int			y;
	t_points	*head;

	y = 0;
	head = points;
	while (points != NULL)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			points->next_y = iterate_list(points, x + fdf->map_width);
			x++;
		}
	}
}

t_fdf			*fdf_init(void)
{
	t_fdf		*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_exit(USAGE_ERR);
	ft_bzero(fdf, sizeof(t_fdf));
	return (fdf);
}
