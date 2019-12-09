/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:41:13 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/07 22:36:00 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_keys(t_coord *t)
{
	mlx_hook(t->win_ptr, 2, 0,key_press, t);
	mlx_hook(t->win_ptr, 17, 0, ft_close, t);
}

void	key_zoom(int keycode, t_coord *t)
{
	if ((keycode == 69 || keycode == 24) && t->zoom <= 200)
		t->zoom+=1;
	else if ((keycode == 78 || keycode == 27) && t->zoom >= 15)
		t->zoom-=1;
	ft_manage_points(t);
}

void	key_move(int keycode, t_coord *t)
{
	if (keycode == 123 && t->x >= 0)
		t->x-=3;
	else if (keycode == 124 && t->x <= 1000)
		t->x+=3;
	else if (keycode == 126 && t->y >= 0)
		t->y+=3;
	else if (keycode == 125 && t->y <= 1000)
		t->y+=3;
}

int		key_press(int keycode, t_coord *t)
{
	if (keycode == 69 || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, t);
	if (keycode == 53)
		ft_close(t->win_ptr);
	if (keycode >= 123 && keycode <= 126)
		key_move(keycode, t);
	ft_manage_points(t);
return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}
