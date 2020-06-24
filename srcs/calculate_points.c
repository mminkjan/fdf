/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_points.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 12:44:41 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/16 16:31:30 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		define_loop(t_fdf *fdf,
					t_points *points,
					double delta_altitude,
					t_points position)
{
	points->x = fdf->tile_size * (int)position.x - (fdf->map_width / 2);
	points->y = fdf->tile_size * (int)position.y - (fdf->map_height / 2);
	if (points->alt != 0 && delta_altitude != 0)
		points->z = fdf->tile_size / delta_altitude * points->alt;
	else
		points->z = 0;
}

static void		define_points(t_fdf *fdf,
					t_points *points)
{
	t_points	position;
	double		delta_altitude;
	t_points	*head;

	position.y = 0;
	head = points;
	delta_altitude = fdf->alt_max - fdf->alt_min;
	if (delta_altitude < 0)
		delta_altitude = abs((int)delta_altitude);
	while (points != NULL)
	{
		position.x = 0;
		while (position.x < fdf->max_x)
		{
			define_loop(fdf, points, delta_altitude, position);
			points = points->next_x;
			position.x++;
		}
		position.y++;
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
		if (points->alt > fdf->alt_max)
			fdf->alt_max = points->alt;
		if (points->alt < fdf->alt_min)
			fdf->alt_min = points->alt;
		points = points->next_x;
	}
	fdf->alt_mid = (fabs(fdf->alt_max) - fabs(fdf->alt_min)) / 2;
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
