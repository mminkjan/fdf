/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:03:52 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/11 17:55:51 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			free_str(char **alt_values)
{
	size_t index;

	index = 0;
	while (alt_values[index])
	{
		ft_bzero(alt_values[index], 1);
		free(alt_values[index]);
		index++;
	}
	free(alt_values);
}

static void			lst_addback(t_points **points,
						t_points *alt)
{
	t_points *temp;

	temp = *points;
	if (temp == NULL)
	{
		*points = alt;
		return ;
	}
	while (temp->next_x != NULL)
		temp = temp->next_x;
	temp->next_x = alt;
}

static t_points		*new_alt_node(char *alt_values)
{
	t_points	*new_node;
	int			value;

	new_node = (t_points*)malloc(sizeof(t_points));
	if (new_node == NULL)
	{
		free(new_node);
		ft_exit(MALLOC_ERR);
	}
	value = (int)ft_atoi(&alt_values[0]);
	new_node->alt = value;
	new_node->next_x = NULL;
	return (new_node);
}

static void			line_extract(t_points **points,
						char **alt_values,
						t_fdf *fdf)
{
	int			length;
	t_points	*temp;

	length = 0;
	while (*alt_values)
	{
		temp = new_alt_node(*(alt_values));
		lst_addback(points, temp);
		alt_values++;
		length++;
	}
	if (fdf->max_x == 0)
		fdf->max_x = length;
	else
	{
		if (fdf->max_x != length)
		{
			lst_del(points, (void (*)(void*, size_t))points);
			ft_exit(INVAL_ERR);
		}
	}
}

void				import_map(t_fdf *fdf,
						t_points **points,
						char **argv)
{
	int		ret_val;
	char	*line;
	char	**alt_values;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit(FILE_ERR);
	ret_val = get_next_line(fd, &line);
	while (ret_val > 0)
	{
		alt_values = ft_strsplit(line, ' ');
		if (alt_values == NULL)
			ft_exit(MALLOC_ERR);
		line_extract(points, alt_values, fdf);
		fdf->max_y += 1;
		free_str(alt_values);
		free(line);
		ret_val = get_next_line(fd, &line);
	}
	free(line);
}
