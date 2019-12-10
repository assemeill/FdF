/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:28:57 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/10 14:16:09 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check(t_coord *t)
{
	char	**check;
	char	*tmp[2];
	char	*blank;
	char	*line;
	int		i;

	t->rows = 0;
	i = 0;
	t->map = NULL;
	blank = " ";
	while (get_next_line(t->fd, &line) != 0)
	{	
		tmp[0] = t->map;
		tmp[1] = ft_strjoin(t->map, line);
		t->map = ft_strjoin(tmp[1], blank);
		ft_strdel(&tmp[0]);
		ft_strdel(&tmp[1]);
		check = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (check[i])
			i++;
		if (t->rows == 0)
			t->rows = i;
		else if (t->rows != i)
			return (0);
		ft_strdel(check);
		i = 0;
	}
	if (t->rows == 0)
		return (0);
	else
		return (t->rows);
}

void	*ft_to_int_array(t_coord *t)
{
	int		i;	
	
	i = 0;
	if (!(t->values = malloc((t->columns + 1) * sizeof(t->values))))
		return (0);
	while (t->list[i])
	{
		t->values[i] = ft_atoi(t->list[i]);
		i++;
	}
	return (0);
}

//void	ft_iso(int x, int y, int z)
//{
//	int		o;
//	int		previous_x;
//	int		previous_y;
//
//	previous_x = t->x;
//	previous_y = t->y;
//	t->x = (previous_x - previous_y) * cos(0.523599);
//	t->y = -(t->z) + (previous_x + previous_y) * sin (0.523599);
//}

void	ft_manage_points(t_coord *t)
{
	int		i;
	int 	n;
	int		o;

	i = 0;
	n = 0;
	o = 0;
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	while (t->list[o])
	{
		t->z = t->values[o];
		if (t->list[o + 1] && n + 1 < t->rows)
		{
			ft_iso(t->xp + n * t->zoom, t->yp + t->zoom * i - t->zoom * t->values[o], values[o]);
			ft_iso(t->xp + (n + 1) * t->zoom, t->yp + t->zoom * i - t->zoom * t->values[o + 1], values[o + 1]);
		}
		if (t->list[o + t->rows] && o + t->rows < t -> columns)
		{
			ft_iso(t->xp + n * t->zoom, t->yp + t->zoom * i - t->zoom * t->values[o], values[o]);
			ft_iso(t->xp + n * t->zoom, t->yp + t->zoom * (i + 1) - t->values[o + t->rows] * t->zoom, values[o + t->rows]);
		}
		n++;
		if (n == t->rows)
		{
			n = 0;
			i++;
		}
		o++;
	}
}

void	ft_create_scene(t_coord *t)
{
	t->columns = 0;
	t->zoom = 20;
	t->xp = 200;
	t->yp = 200;
	t->x = 0;
	t->y = 0;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2000, 1000, "fdf");
	while (t->map[t->columns])
		t->columns++;
	ft_to_int_array(t);
	ft_manage_points(t);
	manage_keys(t);
	mlx_loop(t->mlx_ptr);
}
