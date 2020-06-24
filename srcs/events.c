/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 13:17:41 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/23 18:38:39 by mminkjan      ########   odam.nl         */
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
	ft_bzero(event, sizeof(t_events));
	event->color_set = 1;
	event->zoom = 1;
	event->iso = 1;
}
