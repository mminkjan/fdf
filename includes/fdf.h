/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:06:39 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/02 18:25:27 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# define USAGE_ERR "usage error: input valid map\n"
# define WIDTH	1200
# define HEIGHT 900

typedef struct			s_points
{
	double				alt;
	double				x;
	double				y;
	double				z;
	double				alt_max;
	double				alt_min;
	int					color;
	struct s_points		*next;
}						t_points;

typedef struct 			 s_fdf
{
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
	char				*map_name;
	char				*addr_str;
	int					bpp;
	int					size_line;	
}						t_fdf;

int						main(int argc, char **argv);
void					mlx_setup(t_fdf *fdf);

#endif