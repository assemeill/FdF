/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:56:41 by aszhilki          #+#    #+#             */
/*   Updated: 2019/12/15 17:57:35 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef	struct	s_coord
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			projection;
	char		*map;
	char		**list;
	int			rows;
	int			*z;
	int			*x;
	int			xp;
	int			*y;
	int			yp;
	int			*xiso;
	int			*yiso;
	int			*ziso;
	int			zoom;
	int			columns;
	int			*values;
	int			check;
	int			i;
	int			*color;
	int			scheme;
}				t_coord;

int				ft_check(t_coord *t);
void			*ft_to_int_array(t_coord *t);
void			ft_manage_points(t_coord *t);
void			ft_draw(int *x0, int *y0, int o, t_coord *t);
void			ft_create_scene(t_coord *t);
void			manage_keys(t_coord *t);
int				key_press(int keycode, t_coord *t);
int				ft_close(void *param, t_coord *t);
void			ft_set_points(t_coord *t);
void			ft_iso(t_coord *t);
void			ft_projection(int *x, int *y, t_coord *t);
int				ft_copy(t_coord *t);
void			ft_panel(t_coord *t);
void			ft_color(t_coord *t);

#endif
