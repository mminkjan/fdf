/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_rotations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:20:20 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/07 11:27:37 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso_projection(t_points *alt_point)
{
	double		prev_x;
	double		prev_y;

	prev_x = alt_point->x;
	prev_y = alt_point->y;
	alt_point->x = (prev_x - prev_y) * cos(30 * PI / 180);
	alt_point->y = -alt_point->z + (prev_x + prev_y) * sin(30 * PI / 180);
}
