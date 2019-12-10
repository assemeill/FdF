/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:56:41 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/10 13:31:21 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <stdio.h>

typedef	struct	s_coord
{
	int 	fd;
	void 	*mlx_ptr;
	void 	*win_ptr;
	char	*map;
	char	**list;
	int		rows;
	int		z;
	int		x;
	int		xp;
	int		y;
	int		yp;
	int		zoom;
	int		columns;
	int		*values;
	int		check;
}		t_coord;

int		ft_check(t_coord *t);
void		*ft_to_int_array(t_coord *t);
void	ft_manage_points(t_coord *t);
void	ft_draw(int x0, int y0, int x1, int y1, t_coord *t);
int		key_press(int keycode, t_coord *t);
void	key_zoom(int keycode, t_coord *t);
int		ft_close(void *param);
void	ft_create_scene(t_coord *t);
void	manage_keys(t_coord *t);
//int		mouse_press(t_coord *t);
//int		mouse_release(t_coord *t);
int		mouse_move(int x, int y, t_coord *t);

#endif