/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:30:21 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/27 19:53:31 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

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

static	void ft_draw(char **values, int rows)
{
		void	*mlx_ptr;
		void	*win_ptr;
		int n;
		n = 0;

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
		while (n < 20)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, 50 + n, 50, 250);
			n++;
		}
		mlx_loop(mlx_ptr);
}

int		main(int argc, char **argv)
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
		ft_draw(values, rows);

	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}
