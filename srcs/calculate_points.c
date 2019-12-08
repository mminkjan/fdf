/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_points.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 12:44:41 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/08 12:55:41 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		set_offset(t_fdf *fdf,
					t_points *points)
{
	points->x -= (fdf->map_width / 2);
	points->y -= (fdf->map_height / 2);
}

static void		define_points(t_fdf *fdf,
					t_points *points)
{
	int			x;
	int			y;
	double		delta_altitude;
	t_points	*head;

	y = 0;
	head = points;
	delta_altitude = fdf->alt_max - fdf->alt_min;
	if (delta_altitude < 0)
		delta_altitude = abs((int)delta_altitude);
	while (points != NULL)
	{
		x = 0;
		while (x < fdf->max_x)
		{
			points->x = fdf->tile_size * x;
			points->y = fdf->tile_size * y;
			points->z = fdf->tile_size / delta_altitude * points->alt;
			set_offset(fdf, points); // moved here
			points = points->next_x;
			x++;
		}
		y++;
	}
	points = head;
}

static void		define_altitude(t_fdf *fdf,
					t_points *points)
{
	t_points	*head;

	head = points;
	fdf->alt_max = points->alt;
	fdf->alt_min = points->alt;
	while (points != NULL)
	{
		if (head->alt > fdf->alt_max)
			fdf->alt_max = points->alt;
		if (head->alt < fdf->alt_min)
			fdf->alt_min = points->alt;
		points = points->next_x;
	}
	points = head;
}

static void		define_map_dimensions(t_fdf *fdf,
					t_points *points)
{
	if (fdf->max_x > fdf->max_y)
		fdf->tile_size = (WIDTH / fdf->max_x) * 0.6;
	else
		fdf->tile_size = (HEIGHT / fdf->max_y) * 0.6;
	fdf->map_width = fdf->tile_size * fdf->max_x;
	fdf->map_height = fdf->tile_size * fdf->max_y;
	define_altitude(fdf, points);
}

void			calculate_points(t_fdf *fdf,
					t_points *points)
{
	define_map_dimensions(fdf, points);
	define_points(fdf, points);
}
