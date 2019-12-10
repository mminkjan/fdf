/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_point.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:20:20 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/10 12:54:12 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		event_rot_x(int pos, t_points *alt_point)
{
	int		prev_y;
	int		prev_z;

	prev_y = alt_point->y;
	prev_z = alt_point->z;
	alt_point->y = prev_y * cos(pos * PI / 180) - prev_z * sin(pos * PI / 180);
	alt_point->z = prev_y * sin(pos * PI / 180) + prev_z * cos(pos * PI / 180);
}

void	event_rot_y(int pos, t_points *alt_point)
{
	int		prev_x;
	int		prev_z;

	prev_x = alt_point->x;
	prev_z = alt_point->z;
	alt_point->x = prev_x * cos(pos * PI / 180) + prev_z * sin(pos * PI / 180);
	alt_point->z = -prev_x * sin(pos * PI / 180) + prev_z * cos(pos * PI / 180);
}

void	event_rot_z(int pos, t_points *alt_point)
{
	int		prev_x;
	int		prev_y;

	prev_x = alt_point->x;
	prev_y = alt_point->y;
	alt_point->x = prev_x * cos(pos * PI / 180) - prev_y * sin(pos * PI / 180);
	alt_point->y = prev_x * sin(pos * PI / 180) + prev_y * cos(pos * PI / 180);
}

void	iso_projection(t_points *alt_point)
{
	int		prev_x;
	int		prev_y;

	prev_x = alt_point->x;
	prev_y = alt_point->y;
	alt_point->x = (prev_x - prev_y) * cos(30 * PI / 180);
	alt_point->y = -alt_point->z + (prev_x + prev_y) * sin(30 * PI / 180);
}
