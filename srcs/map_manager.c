/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_manager.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:40:17 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/07 15:02:12 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		center_point(t_fdf *fdf, t_points *alt_point)
{
	fdf->events.move_x = 0;
	fdf->events.move_y = 0;

	alt_point->x += WIDTH / 2 - fdf->events.move_x;
	alt_point->y += HEIGHT / 2 - fdf->events.move_y;
}

t_points	alt_point(t_fdf *fdf, t_points *point)
{
	t_points *alt_point;
	// t_events *event = fdf->events;

	alt_point = point;
	// if (event->rot_x != 0)
	// 	event_rot_x(event->rot_x, alt_point);
	// if (event->rot_y != 0)
	// 	event_rot_y(event->rot_y, alt_point);
	// if (event->rot_z != 0)
	// 	event_rot_z(event->rot_z, alt_point);
	// if (event->extend != 0)
	// 	event_extend(event->extend, alt_point);
	// if (event->zoom != 0)
	// 	event_zoom(event->zoom, alt_point);
	iso_projection(alt_point);
	center_point(fdf, alt_point);
	return (*alt_point);
}

void	print_lines(t_fdf *fdf)
{
	int			x;
	int			y;
	t_points	*start;
	t_points	*point = fdf->points;

	y = 0;
	// printf("%f\n", point->alt);
	while (point != NULL)
	{
		x = 0;
		while (x < fdf->max_x)
		{
			start = point;
			alt_point(fdf, start);
			if (x + 1 < fdf->max_x)
			{
				draw_line(fdf, *start, alt_point(fdf, start->next_x));
			}
			if (y + 1 < fdf->max_y)
				draw_line(fdf, *start, alt_point(fdf, start->next_y));
			point = point->next_x;
			x++;
		}
		y++;
	}
}

int		map_manager(t_fdf *fdf)
{
	mlx_hook(fdf->window_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->window_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->window_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->window_ptr, 6, 0, mouse_move, fdf);
	// printf("%f - %f\n", fdf->points->x, fdf->points->y);
	print_lines(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->window_ptr, fdf->image_ptr, 0, 0);
	ft_bzero(fdf->addr_str, fdf->bpp / 8);
	return (0);
}
