/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:18:13 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/10 19:43:36 by jesmith       ########   odam.nl         */
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
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 150, color,
		"y-axis rotation:  q & e\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 180, color,
		"z-axis rotation:  a & d\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 210, color,
		"zoom:             scroll\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 240, color,
		"change height:    + & -\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 270, color,
		"change color:     1, 2, 3\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 300, color,
		"iso projection:   i\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 330, color,
		"top projection:   0\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 360, color,
		"reset:            backspace\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 390, color,
		"quit:             escape\n");
	print_side_line(fdf);
}
