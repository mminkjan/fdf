/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:20:17 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/11 11:56:03 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			get_bit_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static void			set_color_to_end(t_color *color, t_events events)
{
	if (events.color_set == 1)
	{
		color->start = ONE_MIDDLE;
		color->end = ONE_END;
	}
	if (events.color_set == 2)
	{
		color->start = TWO_MIDDLE;
		color->end = TWO_END;
	}
	if (events.color_set == 3)
	{
		color->start = THREE_MIDDLE;
		color->end = THREE_END;
	}
	if (events.color_set == 4)
	{
		color->start = FOUR_MIDDLE;
		color->end = FOUR_END;
	}
	if (events.color_set == 5)
	{
		color->start = FIVE_MIDDLE;
		color->end = FIVE_END;
	}
}

static void			set_color_to_mid(t_color *color, t_events events)
{
	if (events.color_set == 1)
	{
		color->start = ONE_START;
		color->end = ONE_MIDDLE;
	}
	if (events.color_set == 2)
	{
		color->start = TWO_START;
		color->end = TWO_MIDDLE;
	}
	if (events.color_set == 3)
	{
		color->start = THREE_START;
		color->end = THREE_MIDDLE;
	}
	if (events.color_set == 4)
	{
		color->start = FOUR_START;
		color->end = FOUR_MIDDLE;
	}
	if (events.color_set == 5)
	{
		color->start = FIVE_START;
		color->end = FIVE_MIDDLE;
	}
}

int					get_color(t_fdf *fdf, double altitude)
{
	t_color color;
	double	percent;
	int		red;
	int		green;
	int		blue;

	percent = percentage(fdf, altitude);
	if (altitude <= fdf->alt_mid)
		set_color_to_mid(&fdf->color, fdf->events);
	else
		set_color_to_end(&fdf->color, fdf->events);
	color = fdf->color;
	red = get_bit_value(
		(color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percent);
	green = get_bit_value(
		(color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percent);
	blue = get_bit_value(color.start & 0xFF, color.end & 0xFF, percent);
	return (red << 16 | green << 8 | blue);
}
