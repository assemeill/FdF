/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:57:30 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/15 17:40:57 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_line_low(int *x0, int *y0, int o, t_coord *t)
{
	int		dy;
	int		yi[2];
	int		y;
	int		x;

	yi[0] = 1;
	dy = y0[t->i + o] - y0[t->i];
	if (dy < 0)
	{
		yi[0] = -1;
		dy = -dy;
	}
	yi[1] = 2 * dy - (x0[t->i + o] - x0[t->i]);
	y = y0[t->i];
	x = x0[t->i];
	while (x++ < x0[t->i + o])
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y, t->color[t->i]);
		if (yi[1] > 0)
		{
			y = y + yi[0];
			yi[1] = yi[1] - 2 * (x0[t->i + o] - x0[t->i]);
		}
		yi[1] = yi[1] + 2 * dy;
	}
}

static	void	ft_line_lower(int *x0, int *y0, int o, t_coord *t)
{
	int		dy;
	int		yi[2];
	int		y;
	int		x;

	yi[0] = 1;
	dy = y0[t->i] - y0[t->i + o];
	if (dy < 0)
	{
		yi[0] = -1;
		dy = -dy;
	}
	yi[1] = 2 * dy - (x0[t->i] - x0[t->i + o]);
	y = y0[t->i + o];
	x = x0[t->i + o];
	while (x++ < x0[t->i])
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y, t->color[t->i]);
		if (yi[1] > 0)
		{
			y = y + yi[0];
			yi[1] = yi[1] - 2 * (x0[t->i] - x0[t->i + o]);
		}
		yi[1] = yi[1] + 2 * dy;
	}
}

static	void	ft_line_high(int *x0, int *y0, int o, t_coord *t)
{
	int		dx;
	int		xi[2];
	int		x;
	int		y;

	xi[0] = 1;
	dx = x0[t->i + o] - x0[t->i];
	if (dx < 0)
	{
		xi[0] = -1;
		dx = -dx;
	}
	xi[1] = 2 * dx - (y0[t->i + o] - y0[t->i]);
	x = x0[t->i];
	y = y0[t->i];
	while (y++ < y0[t->i + o])
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y, t->color[t->i]);
		if (xi[1] > 0)
		{
			x = x + xi[0];
			xi[1] = xi[1] - 2 * (y0[t->i + o] - y0[t->i]);
		}
		xi[1] = xi[1] + 2 * dx;
	}
}

static	void	ft_line_higher(int *x0, int *y0, int o, t_coord *t)
{
	int		dx;
	int		xi[2];
	int		x;
	int		y;

	xi[0] = 1;
	dx = x0[t->i] - x0[t->i + o];
	if (dx < 0)
	{
		xi[0] = -1;
		dx = -dx;
	}
	xi[1] = 2 * dx - (y0[t->i] - y0[t->i + o]);
	x = x0[t->i + o];
	y = y0[t->i + o];
	while (y++ < y0[t->i])
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y, t->color[t->i]);
		if (xi[1] > 0)
		{
			x = x + xi[0];
			xi[1] = xi[1] - 2 * (y0[t->i] - y0[t->i + o]);
		}
		xi[1] = xi[1] + 2 * dx;
	}
}

void			ft_draw(int *x0, int *y0, int o, t_coord *t)
{
	if (ft_abs(y0[t->i + o] - y0[t->i]) < ft_abs(x0[t->i + o] - x0[t->i]))
	{
		if (x0[t->i] > x0[t->i + o])
			ft_line_lower(x0, y0, o, t);
		else
			ft_line_low(x0, y0, o, t);
	}
	else
	{
		if (y0[t->i] > y0[t->i + o])
			ft_line_higher(x0, y0, o, t);
		else
			ft_line_high(x0, y0, o, t);
	}
}
