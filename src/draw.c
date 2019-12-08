/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:57:30 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/06 17:59:15 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_plot_line_low(int x0, int y0, int x1, int y1, t_coord *t)
{
	int		dx;
	int		dy;
	int		yi;
	int		y;
	int		error;

	yi = 1;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	error = 2*dy - dx;
	y = y0;
	while (x0++ < x1)
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x0, y, 250);
		if (error > 0)
		{
			y = y + yi;
			error = error - 2*dx;
		}
		error = error + 2*dy;
	}

}

static	void	ft_plot_line_high(int x0, int y0, int x1, int y1, t_coord *t)
{
	int		dx;
	int		dy;
	int		xi;
	int		x;
	int		error;

	xi = 1;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	error = 2*dx - dy;
	x = x0;
	while (y0++ < y1)
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y0, 250);
		if (error > 0)
		{
			x = x + xi;
			error = error - 2*dy;
		}
		error = error + 2*dx;
	}

}

void			ft_draw(int x0, int y0, int x1, int y1, t_coord *t)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			ft_plot_line_low(x1, y1, x0, y0, t);
		else
			ft_plot_line_low(x0, y0, x1, y1, t);
	}
	else
	{
		if (y0 > y1)
			ft_plot_line_high(x1, y1, x0, y0, t);
		else
			ft_plot_line_high(x0, y0, x1, y1, t);
	}
}

