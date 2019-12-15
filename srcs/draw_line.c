/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Malou <Malou@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 14:37:04 by Malou          #+#    #+#                */
/*   Updated: 2019/12/12 18:06:47 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		put_pixel(t_fdf *fdf, t_points point)
{
	int		index;

	if (point.x >= 0 && point.x < WIDTH && point.y >= 0
	&& point.y < HEIGHT)
	{
		index = ((int)point.y * fdf->size_line) + ((int)point.x * fdf->bpp / 8);
		fdf->addr_str[index] = point.color;
		index++;
		fdf->addr_str[index] = point.color >> 8;
		index++;
		fdf->addr_str[index] = point.color >> 16;
	}
}

static void		draw_y_dominant(t_fdf *fdf, t_line *line,
					t_points start, t_points end)
{
	t_points point;

	point = start;
	line->delta_alt = (end.alt - start.alt) / line->delta_y_abs;
	point.alt = start.alt;
	while (point.y < end.y)
	{
		if (line->error_y <= 0)
			line->error_y += 2 * line->delta_x_abs;
		else
		{
			if ((line->delta_x < 0 && line->delta_y < 0) ||
			(line->delta_x > 0 && line->delta_y > 0))
				point.x++;
			else
				point.x--;
			line->error_y += 2 * (line->delta_x_abs - line->delta_y_abs);
		}
		point.alt += line->delta_alt;
		point.color = get_color(fdf, point.alt);
		put_pixel(fdf, point);
		point.y++;
	}
}

static void		draw_x_dominant(t_fdf *fdf, t_line *line,
					t_points start, t_points end)
{
	t_points point;

	point = start;
	line->delta_alt = (end.alt - start.alt) / line->delta_x_abs;
	point.alt = start.alt;
	while (point.x < end.x)
	{
		if (line->error_x < 0)
			line->error_x += 2 * line->delta_y_abs;
		else
		{
			if ((line->delta_x < 0 && line->delta_y < 0) ||
			(line->delta_x > 0 && line->delta_y > 0))
				point.y++;
			else
				point.y--;
			line->error_x += 2 * (line->delta_y_abs - line->delta_x_abs);
		}
		point.alt += line->delta_alt;
		point.color = get_color(fdf, point.alt);
		put_pixel(fdf, point);
		point.x++; 
	}
}

static void		set_direction(t_fdf *fdf, t_line *line,
					t_points start, t_points end)
{
	if ((line->delta_x < 0 && line->delta_y_abs <= line->delta_x_abs) ||
		(line->delta_y < 0 && line->delta_y_abs > line->delta_x_abs))
		swap_points(&start, &end);
	if (line->delta_y_abs <= line->delta_x_abs)
		draw_x_dominant(fdf, line, start, end);
	else
		draw_y_dominant(fdf, line, start, end);
}

void			draw_line(t_fdf *fdf, t_points start, t_points end)
{
	t_line line;

	line.delta_x = end.x - start.x;
	line.delta_y = end.y - start.y;
	line.delta_x_abs = abs((int)line.delta_x);
	line.delta_y_abs = abs((int)line.delta_y);
	line.error_x = 2 * line.delta_y_abs - line.delta_x_abs;
	line.error_y = 2 * line.delta_x_abs - line.delta_y_abs;
	set_direction(fdf, &line, start, end);
}
