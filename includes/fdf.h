/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 13:01:00 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"

# define WIN "WireCraft 0.06.2"

typedef struct	s_coor
{
	float		x;
	float		y;
	float		z;
}				t_coor;

typedef struct	s_map
{
	double		**tab;
	double		x;
	double		y;
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

int				coord_crafter(int fd, t_map **map);
void			ft_tabdel(void *tab, size_t len);
void			ft_memclr(void *ap, size_t len);
int				ft_exit(int key, void *param);
int				put_line(t_data **data, t_coor start, t_coor end);
int				wiremap2(t_data **data, t_map *map);
int				*ft_intset(int *tab, int i, int size);

#endif
