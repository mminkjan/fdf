/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:06:39 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/03 12:28:24 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h> // delete later!

# define USAGE_ERR	"usage error: input valid map\n"
# define FILE_ERR	"error: opening file\n"
# define MALLOC_ERR	"error: malloc\n"
# define INVAL_ERR	"error: invalid map\n"

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

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
	char				*map_name;
	char				*addr_str;
	int					bpp;
	int					size_line;
	int					map_width;
	int					map_height;
}						t_fdf;

int						main(int argc, char **argv);
void					mlx_setup(t_fdf *fdf);
void					import_map(t_fdf *fdf, t_points **points, char **argv);

t_fdf					*fdf_init(void);

#endif
