/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:18:13 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/23 18:24:01 by mminkjan      ########   odam.nl         */
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
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 120, 0xafafaf,
		"x-axis rotation:  w & s\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 150, 0xafafaf,
		"y-axis rotation:  q & e\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 180, 0xafafaf,
		"z-axis rotation:  a & d\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 210, 0xafafaf,
		"zoom:             scroll\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 240, 0xafafaf,
		"change height:    + & -\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 270, 0xafafaf,
		"change color:     1, 2, 3, 4, 5\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 300, 0xafafaf,
		"iso projection:   i\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 330, 0xafafaf,
		"top projection:   0\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 360, 0xafafaf,
		"drag mouse to move map\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 410, 0xafafaf,
		"reset:            backspace\n");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 50, 440, 0xafafaf,
		"quit:             escape\n");
	print_side_line(fdf);
}
