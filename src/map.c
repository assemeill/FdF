/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:28:57 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/14 18:32:41 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check(t_coord *t)
{
	t->rows = 0;
	t->map = NULL;
	ft_copy(t);
	if (ft_copy(t) > 0)
		return (t->rows);
	else
		return (0);
}

int		ft_copy(t_coord *t)
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
		else if (t->rows != i)
			return (0);
		ft_strdel(check);
		i = 0;
	}
	return (t->rows);
}

void	*ft_to_int_array(t_coord *t)
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
	while (t->list[i])
	{
		t->values[i] = ft_atoi(t->list[i]);
		i++;
	}
	return (0);
}

void	ft_create_scene(t_coord *t)
{
	t->columns = 0;
	t->zoom = 20;
	t->xp = 1000;
	t->yp = 200;
	t->projection = 1;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2000, 1000, "fdf");
	while (t->list[t->columns])
		t->columns++;
	ft_to_int_array(t);
	ft_manage_points(t);
	manage_keys(t);
	mlx_loop(t->mlx_ptr);
}
