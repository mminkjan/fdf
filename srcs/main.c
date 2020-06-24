/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:02:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/11 13:37:05 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	validate_argument(char *program, char *argument, t_fdf *fdf)
{
	if (ft_strcmp(program, argument) == 0 ||
		ft_strcmp(&program[2], argument) == 0)
		ft_exit(INVAL_ERR, 0, fdf);
}

int			main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = NULL;
	if (argc != 2)
		ft_exit(USAGE_ERR, 0, fdf);
	validate_argument(argv[0], argv[1], fdf);
	fdf = fdf_init();
	fdf->map_name = ft_strdup(argv[1]);
	mlx_setup(fdf);
	import_map(fdf, &fdf->points, argv);
	calculate_points(fdf, fdf->points);
	order_list(fdf, fdf->points);
	mlx_loop_hook(fdf->mlx_ptr, map_manager, fdf);
	print_interface(fdf);
	mlx_loop(fdf->mlx_ptr);
}
