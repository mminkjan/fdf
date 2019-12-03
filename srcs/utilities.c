/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:01:31 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/03 10:02:50 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_exit(USAGE_ERR);
	ft_bzero(fdf, sizeof(t_fdf));
	return (fdf);
}
