/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:02:56 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/03 11:35:17 by jesmith       ########   odam.nl         */
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
	while (points->next != NULL)
	{
		printf("%f\n", points->alt);
		points = points->next;
	}
	// calculate_points(&fdf, &points); //keep track of head of list here
	mlx_loop(fdf->mlx_ptr);
}
