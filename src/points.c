/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:23:37 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/14 22:49:17 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_coord *t)
{
	int		previous_x;
	int		previous_y;
	int		i;

	i = 0;
	while (t->list[i])
	{
		previous_x = t->x[i];
		previous_y = t->y[i];
		t->xiso[i] = (previous_x - previous_y) * cos(0.523599);
		t->yiso[i] = (previous_x + previous_y) * sin(0.523599) - t->z[i];
		i++;
	}
}

void	ft_set_points(t_coord *t)
{
	int		i;
	int		n;
	int		o;

	i = 0;
	n = 0;
	o = 0;
	while (t->list[o])
	{
		t->z[o] = t->values[o];
		t->x[o] = n;
		t->y[o] = i;
		t->x[o] *= t->zoom;
		t->y[o] *= t->zoom;
		t->z[o] *= t->zoom;
		t->x[o] += t->xp;
		t->y[o] += t->yp;
		n++;
		if (n == t->rows)
		{
			n = 0;
			i++;
		}
		o++;
	}
}

void	ft_projection(int *x, int *y, t_coord *t)
{
	int		n;

	n = 0;
	t->i = 0;
	while (t->list[t->i])
	{
		if (t->list[t->i + 1] && n++ + 1 < t->rows)
			ft_draw(x, y, 1, t);
		if (t->list[t->i + t->rows] && t->i + t->rows < t->columns)
			ft_draw(x, y, t->rows, t);
		if (n == t->rows)
			n = 0;
		t->i += 1;
	}
}

void	ft_manage_points(t_coord *t)
{
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	ft_panel(t);
	ft_set_points(t);
	ft_iso(t);
	if (t->projection == 1)
		ft_projection(t->x, t->y, t);
	else
		ft_projection(t->xiso, t->yiso, t);
}
