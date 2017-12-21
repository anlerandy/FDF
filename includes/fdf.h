/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/21 21:35:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"

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

int				draw_line(void *mlx, void *win, t_coor start, t_coor end);
int				coord_crafter(int fd, t_map **map);
void			ft_tabdel(void *tab, size_t len);
int				wiremap(void *mlx, void *win, t_map *map);

#endif
