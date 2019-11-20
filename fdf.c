/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:30:21 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/19 18:54:34 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static int		ft_check(const int fd)
{
	char	**map;
	char	**tmp;
	char	*line;
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	tmp = NULL;
	map = NULL;
	while (get_next_line(fd, &line) != 0)
	{	
		*tmp = ft_strsplit(line, ' ');
		ft_strjoin(*map, *line);
		ft_strdel(&line);
		while (tmp[i])
			i++;
		if (rows == 0)
			rows = i;
		else if (rows != i)
			return (0);
		ft_strdel(tmp);
		ft_strsplit(**map, ' ');
		return (rows);
	}
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		rows;
	int 	n;
	int		fd;

	if (argc == 2)
	{
		n = 0;
		fd = open(argv[1], O_RDONLY);
		if (!(rows = ft_check(fd)))
			ft_putchar("Invalid file\n");
		else
			printf("%s\n", map);

//		mlx_ptr = mlx_init();
//		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
//		while (n < 20)
//		{
//			mlx_pixel_put(mlx_ptr, win_ptr, 50 + n, 50, 250);
//			n++;
//		}
//		mlx_loop(mlx_ptr);
	}
	else
		ft_putchar("Usage : ./fdf <filename> [ case_size z_size ]\n");
}
