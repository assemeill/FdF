/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:18:00 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/15 17:54:59 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	grey(t_coord *t)
{
	int i;

	i = -1;
	while (i++ < t->columns)
	{
		if (t->z[i] < 10)
			t->color[i] = 0xFFFFFF;
		else if (t->z[i] >= 10 && t->z[i] < 30)
			t->color[i] = 0xF4F4F4;
		else if (t->z[i] >= 30 && t->z[i] < 60)
			t->color[i] = 0xD4D4D4;
		else if (t->z[i] >= 60)
			t->color[i] = 0x888888;
	}
}

static void	orange(t_coord *t)
{
	int i;

	i = -1;
	while (i++ < t->columns)
	{
		if (t->z[i] < 10)
			t->color[i] = 0xFF4500;
		else if (t->z[i] >= 10 && t->z[i] < 30)
			t->color[i] = 0xFF6A33;
		else if (t->z[i] >= 30 && t->z[i] < 60)
			t->color[i] = 0xFFb397;
		else if (t->z[i] >= 60)
			t->color[i] = 0xFFCEBD;
	}
}

void		ft_color(t_coord *t)
{
	if (t->scheme == 1)
		grey(t);
	else
		orange(t);
}
