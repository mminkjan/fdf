/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_points.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 12:44:41 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/03 14:29:52 by jesmith       ########   odam.nl         */
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
		abs(delta_altitude);
	while (head != NULL)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			points->x = fdf->tile_size * x;
			points->y = fdf->tile_size * y;
			points->z = fdf->tile_size / delta_altitude * points->alt;
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
	double		altitude;

	head = points;
	fdf->alt_max = points->alt;
	fdf->alt_min = points->alt;
	while (head != NULL)
	{
		if (head->alt > fdf->alt_max)
			fdf->alt_max = points->alt;
		if (head->alt < fdf->alt_min)
			fdf->alt_min = points->alt;
		points = points->next;
	}
	points = head;
}

static void		define_map_dimensions(t_fdf *fdf,
					t_points *points)
{
	if (fdf->map_width > fdf->map_height)
		fdf->tile_size = (WIDTH / fdf->map_width) * 0.6;
	else
		fdf->tile_size = (HEIGHT / fdf->map_height) * 0.6;
	fdf->map_width *= fdf->tile_size;
	fdf->map_height *= fdf->tile_size;
	define_altitude(fdf, points);
}

void		calculate_points(t_fdf *fdf,
				t_points *points)
{
	define_map_dimensions(fdf, points);
	define_points(fdf, points);
	set_offset(fdf, points);
}
