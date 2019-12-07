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

int	ft_check(const int fd, char **map)
{
	char	**check;
	char	*tmp[2];
	char	*blank;
	char	*line;
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	*map = NULL;
	blank = " ";
	while (get_next_line(fd, &line) != 0)
	{	
		tmp[0] = *map;
		tmp[1] = ft_strjoin(*map, line);
		*map = ft_strjoin(tmp[1], blank);
		ft_strdel(&tmp[0]);
		ft_strdel(&tmp[1]);
		check = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (check[i])
			i++;
		if (rows == 0)
			rows = i;
		else if (rows != i)
			return (0);
		ft_strdel(check);
		i = 0;
	}
	if (rows == 0)
		return (0);
	else
		return (rows);
}

int		*ft_to_int_array(char **map, int len)
{
	int		i;	
	int		*values;
	
	i = 0;
	len -= 1;
	if (!(values = malloc((len + 1) * sizeof(*values))))
		return (0);
	while (map[i])
	{
		values[i] = ft_atoi(map[i]);
		i++;
	}
	values[i] = '\0';
	return (values);
}

void	ft_manage_points(char **map, int rows)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*values;
	int		x;
	int		y;
	int		i;
	int 	n;
	int		o;
	int		zoom;
	int		columns;


	columns = 0;
	i = 0;
	n = 0;
	o = 0;
	zoom = 20;
	x = 500;
	y = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "fdf");
//	mlx_string_put(mlx_ptr, win_ptr, 20, 60, 0xE0C3FC,"Controls:");
//	while (pix++ < 1000)
//		mlx_pixel_put(mlx_ptr, win_ptr, pix, pix, 0xAAAAAA);
	while (map[columns])
		columns++;
	values = ft_to_int_array(map, columns + 1);
	while (map[o])
	{
		if (map[o + 1] && n + 1 < rows)
			ft_draw(x + n * zoom, y + zoom * i + zoom * values[o], x + (n + 1) * zoom, y + zoom * i + zoom * values[o + 1], mlx_ptr, win_ptr);
		if (map[o + rows])
			ft_draw(x + n * zoom, y + zoom * i + zoom * values[o], x + n * zoom, y + zoom * (i + 1) + values[o + rows] * zoom, mlx_ptr, win_ptr);
		n++;
		if (n == rows)
		{
			n = 0;
			i++;
		}
		o++;
	}
	manage_keys(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}


