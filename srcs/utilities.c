/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:01:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/11 13:29:28 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_exit(char *str, int fd, t_fdf *fdf)
{
	ft_putstr(str);
	close(fd);
	if (fdf != NULL)
	{
		ft_bzero(fdf, sizeof(fdf));
		free(fdf);
	}
	exit(0);
}

double			percentage(t_fdf *fdf, double current)
{
	double placement;
	double distance;

	if (current < fdf->alt_mid)
	{
		placement = current - fdf->alt_min;
		distance = fdf->alt_mid - fdf->alt_min;
	}
	else
	{
		placement = current - fdf->alt_mid;
		distance = fdf->alt_max - fdf->alt_mid;
	}
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void			swap_points(t_points *a, t_points *b)
{
	t_points hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

t_fdf			*fdf_init(void)
{
	t_fdf		*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_exit(USAGE_ERR, 0, fdf);
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->events.color_set = 1;
	fdf->events.zoom = 1;
	fdf->events.iso = 1;
	return (fdf);
}

void			free_structs(t_fdf *fdf)
{
	lst_del(&fdf->points, &ft_del);
	ft_bzero(fdf, sizeof(t_fdf));
	free(fdf);
}
