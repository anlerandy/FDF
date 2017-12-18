/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/18 15:58:00 by alerandy         ###   ########.fr       */
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

typedef struct	s_cortab
{
	int			*tab;
	int			y;
	int			len;
}				t_cortab;

int				draw_line(void *mlx, void *win, t_coor start, t_coor end);
int				open_map(char *arg);

#endif
