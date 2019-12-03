/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_manager.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:40:17 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/03 15:16:01 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		map_manager(t_fdf *fdf)
{
	mlx_hook(fdf->window_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->window_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->window_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->window_ptr, 6, 0, mouse_move, fdf);
	print_lines(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, fdf->image_ptr, 0, 0);
	ft_bzero(fdf->addr_str, fdf->bpp / 8);
	return (0);
}
