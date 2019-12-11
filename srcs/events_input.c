/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:07:16 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/11 15:03:05 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				mouse_move(int x,
					int y,
					t_fdf *fdf)
{
	if (fdf->events.mouse_press == 1)
	{
		fdf->events.move_x = (fdf->map_width / 2) + (WIDTH / 2) - x;
		fdf->events.move_y = ((fdf->map_height / 2) - 400) + (HEIGHT / 2) - y;
	}
	return (0);
}

int				mouse_press(int button,
					int x,
					int y,
					t_fdf *fdf)
{
	x = 0;
	y = 0;
	if (button == 4 && fdf->events.zoom > 0.1)
		fdf->events.zoom -= 0.1;
	if (button == 5)
		fdf->events.zoom += 0.1;
	if (button == 1)
		fdf->events.mouse_press = 1;
	return (0);
}

int				mouse_release(int button,
					int x,
					int y,
					t_fdf *fdf)
{
	x = 0;
	y = 0;
	if (button == 1)
		fdf->events.mouse_press = 0;
	return (0);
}

static void		key_press2(int key_code,
					t_fdf *fdf)
{
	if (key_code == PLUS)
		fdf->events.extend++;
	if (key_code == MIN)
		fdf->events.extend--;
	if (key_code == ONE)
		fdf->events.color_set = 1;
	if (key_code == TWO)
		fdf->events.color_set = 2;
	if (key_code == THREE)
		fdf->events.color_set = 3;
	if (key_code == FOUR)
		fdf->events.color_set = 4;
	if (key_code == FIVE)
		fdf->events.color_set = 5;
	if (key_code == ZERO)
		fdf->events.iso = 0;
	if (key_code == I)
		fdf->events.iso = 1;
	if (key_code == ESC)
	{
		// ft_free(fdf, points)
		exit(0);
	}
	if (key_code == M)
		fdf->events.smooth_exit++;
}

int				key_press(int key_code,
					t_fdf *fdf)
{
	if (key_code == DEL)
		fdf->events.reset = 1;
	if (key_code == W)
		fdf->events.rot_x++;
	if (key_code == S)
		fdf->events.rot_x--;
	if (key_code == E)
		fdf->events.rot_y++;
	if (key_code == Q)
		fdf->events.rot_y--;
	if (key_code == D)
		fdf->events.rot_z--;
	if (key_code == A)
		fdf->events.rot_z++;
	key_press2(key_code, fdf);
	return (0);
}
