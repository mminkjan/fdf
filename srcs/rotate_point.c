/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_point.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:20:20 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/06 19:12:12 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	event_rot_x(int pos, t_points *alt_point)
{
	int		prev_y;
	int		prev_z;
	double	angle;

	angle = pos * PI / 180;
	prev_y = alt_point->y;
	prev_z = alt_point->z;
	alt_point->y = prev_y * cos(angle) - prev_z * sin(angle);
	alt_point->z = prev_y * sin(angle) + prev_z * cos(angle);
}

void	event_rot_y(int pos, t_points *alt_point)
{
	int		prev_x;
	int		prev_z;
	double	angle;

	angle = pos * PI / 180;
	prev_x = alt_point->x;
	prev_z = alt_point->z;
	alt_point->x = prev_x * cos(angle) + prev_z * sin(angle);
	alt_point->z = -prev_x * sin(angle) + prev_z * cos(angle);
}

void	event_rot_z(int pos, t_points *alt_point)
{
	int		prev_x;
	int		prev_y;
	double	angle;

	angle = pos * PI / 180;
	prev_x = alt_point->x;
	prev_y = alt_point->y;
	alt_point->x = prev_x * cos(angle) - prev_y * sin(angle);
	alt_point->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	iso_projection(t_points *alt_point)
{
	int		prev_x;
	int		prev_y;
	double	angle;

	angle = 30 * PI / 180;
	prev_x = alt_point->x;
	prev_y = alt_point->y;
	alt_point->x = (prev_x - prev_y) * cos(angle);
	alt_point->y = -alt_point->z + (prev_x + prev_y) * sin(angle);
}
