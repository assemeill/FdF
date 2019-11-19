/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:30:21 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/17 00:18:12 by aszhilki         ###   ########.fr       */
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
	int		n;
	int		i;

	n = 0;
	i = 0;
	tmp = NULL;
	map = NULL;
	while (get_next_line(fd, &line) != 0)
	{	
		*tmp = ft_strjoin(ft_strsplit(line, ' '), ".");
		ft_strdel(&line);
		ft_strjoin(*map, *tmp);
		while (tmp[i])
			i++;
		if (n == 0)
			n = i;
		else if (n != i)
			return (0);
		ft_strdel(tmp);
	}
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int 	n;
	int		fd;

	if (argc == 2)
	{
		n = 0;
		fd = open(argv[1], O_RDONLY);
		if (!(map = ft_check(fd)))
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
