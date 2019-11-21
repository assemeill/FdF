/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:30:21 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/20 17:13:49 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static int	ft_check(const int fd, char ***map)
{
	char	**tmp;
	char	*line;
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	tmp = NULL;
	while (get_next_line(fd, &line) != 0)
	{	
		ft_strjoin(***map, line);
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (tmp[i])
			i++;
		if (rows == 0)
			rows = i;
		else if (rows != i)
			return (0);
		ft_strdel(tmp);
		i = 0;
	}
	if (rows == 0)
		return (0);
	else
		ft_strsplit(**map, ' ');
		return (rows);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		rows;
	int 	n;
	int		fd;

	map = NULL;
	if (argc == 2)
	{
		n = 0;
		fd = open(argv[1], O_RDONLY);
		if (!(rows = ft_check(fd, &map)))
			ft_putstr("Invalid file\n");
		else
			printf("%s\n", *map);

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
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}
