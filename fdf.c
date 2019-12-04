/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:30:21 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/03 18:42:26 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <math.h>
#include <stdio.h>

static	void	ft_plot_line_low(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
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
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y, 250);
		if (error > 0)
		{
			y = y + yi;
			error = error - 2*dx;
		}
		error = error + 2*dy;
	}

}

static	void	ft_plot_line_high(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
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
		mlx_pixel_put(mlx_ptr, win_ptr, x, y0, 250);
		if (error > 0)
		{
			x = x + xi;
			error = error - 2*dy;
		}
		error = error + 2*dx;
	}

}

static	void	ft_draw(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			ft_plot_line_low(x1, y1, x0, y0, mlx_ptr, win_ptr);
		else
			ft_plot_line_low(x0, y0, x1, y1, mlx_ptr, win_ptr);
	}
	else
	{
		if (y0 > y1)
			ft_plot_line_high(x1, y1, x0, y0, mlx_ptr, win_ptr);
		else
			ft_plot_line_high(x0, y0, x1, y1, mlx_ptr, win_ptr);
	}
}

static int	ft_check(const int fd, char **map)
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

static int		*ft_to_int_array(char **map, int len)
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

static	void	ft_manage_points(char **map, int rows)
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

	int pix = 10;

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
//	while (1)
//		;
	mlx_loop(mlx_ptr);
}

int				main(int argc, char **argv)
{
	char	*map;
	char	**values;
	int		rows;
	int		fd;

		
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(rows = ft_check(fd, &map)))
		{
			ft_putstr("Invalid file\n");
			return (0);
		}
		values = ft_strsplit(map, ' ');
		ft_manage_points(values, rows);

	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}
