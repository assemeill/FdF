/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:41:13 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/15 18:15:04 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		key_zoom(int keycode, t_coord *t)
{
	if ((keycode == 69 || keycode == 24) && t->zoom <= 200)
		t->zoom += 1;
	else if ((keycode == 78 || keycode == 27) && t->zoom >= 15)
		t->zoom -= 1;
}

static void		key_move(int keycode, t_coord *t)
{
	if (keycode == 123)
		t->xp -= 3;
	else if (keycode == 124)
		t->xp += 3;
	else if (keycode == 126)
		t->yp -= 3;
	else if (keycode == 125)
		t->yp += 3;
}

static void		change_pr(int keycode, t_coord *t)
{
	if (keycode == 49)
	{
		if (t->projection == 0)
			t->projection = 1;
		else
			t->projection = 0;
	}
	else if (keycode == 48)
	{
		if (t->scheme == 0)
			t->scheme = 1;
		else
			t->scheme = 0;
	}
}

int				key_press(int keycode, t_coord *t)
{
	if (keycode == 69 || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, t);
	if (keycode == 53)
		ft_close(t->win_ptr, t);
	if (keycode == 49 || keycode == 48)
		change_pr(keycode, t);
	if (keycode >= 123 && keycode <= 126)
		key_move(keycode, t);
	ft_manage_points(t);
	return (0);
}

int				ft_close(void *param, t_coord *t)
{
	(void)param;
	free(t->values);
	free(t->xiso);
	free(t->yiso);
	free(t->x);
	free(t->y);
	free(t->z);
	free(t->color);
	free(t);
	exit(0);
}
