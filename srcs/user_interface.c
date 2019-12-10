/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:18:13 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/10 17:26:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		print_side_line(t_fdf *fdf)
{
	int y;
	int color;

	y = 0;
	color = 0xfafafaf;
	while (y < HEIGHT)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->window_ptr, 399, y, color);
		y++;
	}
}

void			print_interface(t_fdf *fdf)
{
	int color;

	color = 0xafafaf;
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 120, color,
		"x-axis rotation:  w & s\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 140, color,
		"y-axis rotation:  q & e\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 160, color,
		"z-axis rotation:  a & d\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 180, color,
		"zoom:             scroll\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 200, color,
		"change height:    + & -\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 220, color,
		"change color:     1, 2, 3\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 240, color,
		"reset:            backspace\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 260, color,
		"quit:             escape\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 280, color,
		"dance and die:    m\n");
	print_side_line(fdf);
}
