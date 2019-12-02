/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:06:39 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/02 16:31:33 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# define	USAGE_ERR	"usage error: input valid map\n"

typedef struct  s_fdf
{
	void		*mlx_pointer;
	void		*window_pointer;
	void		*image_pointer;
	char		*map_title;
	char		*addr_str;
	int			bpp;
	int			size_line;	
}				t_fdf;





#endif