/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/16 11:44:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"

# define WIN "WireCraft 0.08"
# define BLUR 0x99000000
# define BLUE 0x0000ff
# define WHITE 0xffffff
# define YELLOW 0xffff00
# define RED 0xff0000

typedef struct	s_coor
{
	float		x;
	float		y;
	float		z;
}				t_coor;

typedef struct	s_map
{
	int			z;
	int			**tab;
	int			x;
	int			y;
}				t_map;

typedef struct	s_frame
{
	void		*pimg;
	char		*img;
	int			bpp;
	int			s_l;
	int			ndia;
}				t_frame;

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
	int			flag;
	int			flag2;
	t_frame		frame;
}				t_data;

int				coord_crafter(int fd, t_map **map);
void			ft_tabdel(void *tab, int len);
void			ft_memclr(void *ap, size_t len);
int				ft_exit(int key, void *param);
int				put_line(t_data **data, t_coor start, t_coor end);
int				wiremap2(t_data **data, t_map *map);
char			*ft_intset(char *tab, int i, int size);
int				ft_zoom(int key, int x, int y, void *param);
int				ft_infinrot(void *param);
void			usage(int err);

#endif
