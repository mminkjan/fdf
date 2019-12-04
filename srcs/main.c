/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:02:56 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/04 18:52:31 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_points	*points;

	if (argc != 2)
		ft_exit(USAGE_ERR);
	fdf = fdf_init();
	fdf->map_name = ft_strdup(argv[1]);
	mlx_setup(fdf);
	import_map(fdf, &points, argv);
	calculate_points(fdf, points);
	order_list(fdf, points);
	mlx_loop_hook(fdf->mlx_ptr, map_manager, fdf);
	mlx_loop(fdf->mlx_ptr);
}
