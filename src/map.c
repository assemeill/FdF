/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:28:57 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/15 17:57:27 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check(t_coord *t)
{
	t->rows = 0;
	t->map = NULL;
	if (ft_copy(t) != 0)
		return (t->rows);
	else
		return (0);
}

int			ft_copy(t_coord *t)
{
	char	**check;
	char	*tmp[2];
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(t->fd, &line) != 0)
	{
		tmp[0] = t->map;
		tmp[1] = ft_strjoin(t->map, line);
		t->map = ft_strjoin(tmp[1], " ");
		ft_strdel(tmp);
		check = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (check[i])
			i++;
		if (t->rows == 0)
			t->rows = i;
		else if (t->rows != i && t->rows != 0)
			return (0);
		ft_strdel(check);
		i = 0;
	}
	return (t->rows);
}

void		*ft_to_int_array(t_coord *t)
{
	int		i;

	i = 0;
	if (!(t->values = malloc((t->columns + 1) * sizeof(t->values))))
		return (0);
	t->xiso = malloc((t->columns + 1) * sizeof(t->values));
	t->yiso = malloc((t->columns + 1) * sizeof(t->values));
	t->ziso = malloc((t->columns + 1) * sizeof(t->values));
	t->x = malloc((t->columns + 1) * sizeof(t->values));
	t->y = malloc((t->columns + 1) * sizeof(t->values));
	t->z = malloc((t->columns + 1) * sizeof(t->values));
	t->color = malloc((t->columns + 1) * sizeof(t->values));
	while (t->list[i])
	{
		t->values[i] = ft_atoi(t->list[i]);
		i++;
	}
	return (0);
}

void		manage_keys(t_coord *t)
{
	mlx_hook(t->win_ptr, 2, 0, key_press, t);
	mlx_hook(t->win_ptr, 17, 0, ft_close, t);
}

void		ft_create_scene(t_coord *t)
{
	t->columns = 0;
	t->zoom = 20;
	t->xp = 1000;
	t->yp = 200;
	t->projection = 1;
	t->scheme = 0;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2000, 1000, "fdf");
	while (t->list[t->columns])
		t->columns++;
	ft_to_int_array(t);
	ft_manage_points(t);
	manage_keys(t);
	mlx_loop(t->mlx_ptr);
}
