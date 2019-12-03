/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:07:16 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/03 16:30:03 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				mouse_move(int x,
					int y,
					t_fdf *fdf)
{
	t_events	*event = fdf->events;

	if (event->mouse_press == 1)
	{
		event->move_x = WIDTH / 2 - x;
		event->move_y = HEIGHT / 2 - y;
	}
	return (0);
}

int				mouse_press(int button,
					int x,
					int y,
					t_fdf *fdf)
{
	t_events	*event = fdf->events;

	x = 0;
	y = 0;
	if (button == 4 && event->zoom > 0)
		event->zoom--;
	if (button == 5)
		event->zoom++;
	if (button == 1)
		event->mouse_press = 1;
	return (0);
}

int				mouse_release(int button,
					int x,
					int y,
					t_fdf *fdf)
{
	t_events	*event = fdf->events;

	x = 0;
	y = 0;
	if (button == 1)
		event->mouse_press = 0;
	return (0);
}

static void		key_press2(int key_code,
					t_fdf *fdf)
{
	t_events	*event = fdf->events;

	if (key_code == MIN)
		event->rise--;
	if (key_code == ONE)
		event->color_set = 0;
	if (key_code == TWO)
		event->color_set = 1;
	if (key_code == THREE)
		event->color_set = 2;
	if (key_code == ESC)
		exit(0);
	if (key_code == DEL)
		event->reset = 1;
	if (key_code == C)
		event->color_set++;
	if (key_code == M)
		event->smooth_exit++;
}

int			key_press(int key_code,
				t_fdf *fdf)
{
	t_events	*event = fdf->events;

	if (key_code == W)
		event->rot_x++;
	if (key_code == S)
		event->rot_x--;
	if (key_code == E)
		event->rot_y++;
	if (key_code == Q)
		event->rot_y--;
	if (key_code == D)
		event->rot_z--;
	if (key_code == A)
		event->rot_z++;
	if (key_code == PLUS)
		event->rise++;
	key_press2(key_code, event);
	return (0);
}
