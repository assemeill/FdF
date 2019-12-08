/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:28:57 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/06 19:08:37 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check(t_coord *t)
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

void		*ft_to_int_array(t_coord *t)
{
	int		i;	
	
	i = 0;
	if (!(t->values = malloc((t->columns + 1) * sizeof(t->values))))
		return (0);
	while (t->map[i])
	{
		t->values[i] = ft_atoi(&(t->map[i]));
		i++;
	}
	t->values[i] = '\0';
	return (0);
}

void	ft_manage_points(t_coord *t)
{
	int		i;
	int 	n;
	int		o;


	t->columns = 0;
	i = 0;
	n = 0;
	o = 0;
	t->zoom = 20;
	t->x = 500;
	t->y = 500;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2000, 1000, "fdf");
	while (t->map[t->columns])
		t->columns++;
	ft_to_int_array(t);
	while (t->map[o])
	{
		if (t->map[o + 1] && n + 1 < t->rows)
			ft_draw(t->x + n * t->zoom, t->y + t->zoom * i + t->zoom * t->values[o], t->x + (n + 1) * t->zoom, t->y + t->zoom * i + t->zoom * t->values[o + 1], t);
		if (t->map[o + t->rows])
			ft_draw(t->x + n * t->zoom, t->y + t->zoom * i + t->zoom * t->values[o], t->x + n * t->zoom, t->y + t->zoom * (i + 1) + t->values[o + t->rows] * t->zoom, t);
		n++;
		if (n == t->rows)
		{
			n = 0;
			i++;
		}
		o++;
	}
	manage_keys(t);
	mlx_loop(t->mlx_ptr);
}
