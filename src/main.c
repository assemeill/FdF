/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:53:59 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/14 21:08:45 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_coord	*t;

	t = (t_coord *)malloc(sizeof(t_coord));
	if (argc == 2)
	{
		t->fd = open(argv[1], O_RDONLY);
		if (ft_check(t) == 0)
		{
			ft_putstr("Invalid file\n");
			return (0);
		}
		t->list = ft_strsplit(t->map, ' ');
		ft_create_scene(t);
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}
