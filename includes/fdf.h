/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/22 06:28:56 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"

# define WIN "WireCraft 0.05"

typedef struct	s_coor
{
	float		x;
	float		y;
	float		z;
}				t_coor;

typedef struct	s_map
{
	int			**tab;
	int			x;
	int			y;
}				t_map;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			fd;
	int			win_h;
	int			win_w;
	double		zoom;
	double		depth;
	double		posx;
	double		posy;
	double		rotx;
	double		roty;
	double		rotz;
	t_map		*map;
	void		*pimg;
	int			*img;
	int			bpp;
	int			s_l;
	int			ndia;
	int			flag;
}				t_data;

int				draw_line(t_data **data, t_coor start, t_coor end);
int				coord_crafter(int fd, t_map **map);
void			ft_tabdel(void *tab, size_t len);
int				wiremap(t_data **data, t_map *map);
void			ft_memclr(void *ap, size_t len);

#endif
