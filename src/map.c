/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:28:57 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/11 18:07:34 by aszhilki         ###   ########.fr       */
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
	t->x = malloc((t->columns + 1) * sizeof(t->values));
	t->y = malloc((t->columns + 1) * sizeof(t->values));
	t->z = malloc((t->columns + 1) * sizeof(t->values));
	while (t->list[i])
	{
		t->values[i] = ft_atoi(t->list[i]);
		i++;
	}
	return (0);
}

void	ft_iso(int *x, int *y, int *z)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - *z;
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
		//tmp solution. Need to solve this
		t->y[o] -= t->z[o];
		n++;
		if (n == t->rows)
		{
			n = 0;
			i++;
		}
		o++;
	}
}	

void	ft_manage_points(t_coord *t)
{
	int		i;
	int 	n;
	int		o;

	i = 0;
	n = 0;
	o = 0;
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	ft_set_points(t);
	while (t->list[o])
	{
		if (t->list[o + 1] && n + 1 < t->rows)
		{
//			ft_iso(&(t->x[o]), &(t->y[o]), &(t->z[o]));
//			ft_iso(&(t->x[o + 1]), &(t->y[o + 1]), &(t->z[o + 1]));
			ft_draw(t->x[o], t->y[o], t->x[o + 1], t->y[o + 1], t);
		}
		if (t->list[o + t->rows] && o + t->rows < t->columns)
		{
//			ft_iso(&(t->x[o]), &(t->y[o]), &(t->z[o]));
//			ft_iso(&(t->x[o + t->rows]), &(t->y[o + t->rows]), &(t->z[o + t->rows]));
			ft_draw(t->x[o], t->y[o], t->x[o + t->rows], t->y[o + t->rows], t);
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
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2000, 1000, "fdf");
	while (t->map[t->columns])
		t->columns++;
	ft_to_int_array(t);
	ft_manage_points(t);
	manage_keys(t);
	mlx_loop(t->mlx_ptr);
}
