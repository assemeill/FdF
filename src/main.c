/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:53:59 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/06 18:31:11 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
