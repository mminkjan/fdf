/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:01:31 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/11 14:37:26 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percentage(t_fdf *fdf, double current)
{
	double placement;
	double distance;

	if (current < fdf->alt_mid)
	{
		placement = current - fdf->alt_min;
		distance = fdf->alt_mid - fdf->alt_min;
	}
	else
	{
		placement = current - fdf->alt_mid;
		distance = fdf->alt_max - fdf->alt_mid;
	}
	return ((distance == 0) ? 1.0 : (placement / distance));
}

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

void			order_list(t_fdf *fdf, t_points *points)
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

t_fdf			*fdf_init(void)
{
	t_fdf		*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_exit(USAGE_ERR);
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->events.color_set = 1;
	fdf->events.iso = 1;
	return (fdf);
}
