/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:20:17 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/10 12:23:25 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_bit_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void		set_color(t_color *color, t_events events)
{
	if (events.color_set == 1)
	{
		color->start = ONE_START;
		color->end = ONE_END;
	}
	if (events.color_set == 2)
	{
		color->start = TWO_START;
		color->end = TWO_END;
	}
	if (events.color_set == 3)
	{
		color->start = THREE_START;
		color->end = THREE_END;
	}
	if (events.color_set == 4)
	{
		color->start = FOUR_START;
		color->end = FOUR_END;
	}
}

double		percentage(double start, double current, double end)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_color(t_fdf *fdf, double altitude)
{
	double	percent;
	t_color	color = fdf->color;
	int		red;
	int		green;
	int		blue;

	percent = percentage(fdf->alt_min, altitude, fdf->alt_max);
	set_color(&fdf->color, fdf->events);
	red = get_bit_value(
		(color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percent);
	green = get_bit_value(
		(color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percent);
	blue = get_bit_value(color.start & 0xFF, color.end & 0xFF, percent);
	return (red << 16 | green << 8 | blue);
}
