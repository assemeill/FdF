/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:41:13 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/06 19:23:15 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_keys(void *mlx_ptr, void *win_ptr)
{
	mlx_hook(win_ptr, 2, 0,key_press, mlx_ptr);
	mlx_hook(win_ptr, 17, 0, close, mlx_ptr);
}

int		key_press(int keycode, void *param)
{
//	if (keycode == 69 || keycode == 78)
//		key_zoom(param);
	if (keycode == 53)
		ft_close(param);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}
