/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 13:17:41 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/10 16:42:11 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	event_zoom(double zoom, t_points *alt_point)
{
	alt_point->x *= zoom;
	alt_point->y *= zoom;
	alt_point->z *= zoom;
}

void	event_extend(double extend, t_points *alt_point)
{
	alt_point->z *= extend;
}

void	event_reset(t_events *event)
{
	printf("yasss\n");
	event->reset = 0;
	event->extend = 0.0;
	event->color_set = 1;
	event->rot_x = 0;
	event->rot_y = 0;
	event->rot_z = 0;
	event->move_x = 0.0;
	event->move_y = 0.0;
	event->zoom = 0.0;
}
