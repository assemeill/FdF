/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:56:41 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/06 19:16:08 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <stdio.h>

int		ft_check(const int fd, char **map);
int		*ft_to_int_array(char **map, int len);
void	ft_manage_points(char **map, int rows);
void	ft_draw(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr);
int		key_press(int keycode, void *param);
int		ft_close(void *param);
void	manage_keys(void *mlx_ptr, void *win_ptr);

#endif
