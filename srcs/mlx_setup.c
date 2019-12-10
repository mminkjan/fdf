/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 18:16:17 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/10 18:11:37 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_setup(t_fdf *fdf)
{
	int		endian;

	endian = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->window_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH + 400, HEIGHT,
		fdf->map_name);
	fdf->image_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->addr_str = mlx_get_data_addr(fdf->image_ptr, &fdf->bpp,
	&fdf->size_line, &endian);
}
