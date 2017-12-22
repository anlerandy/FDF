/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wired_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:37:16 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/22 00:30:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

static void		ft_rot_x(double *x, double *y, double a)
{
	double		teta;
	double		xtmp;

	xtmp = *x;
	teta = a * ((2 * M_PI) / 360.);
	*x = ((double)*x * cos(teta)) - ((double)*y * sin(teta));
	*y = (xtmp * sin(teta)) + ((double)*y * cos(teta));
}

static t_coor	ft_vector(double z, double x, double y)
{
	t_coor		point;
	double		posx;
	double		posy;
	double		zom;
	double		prof;

	posx = 0;
	posy = 500;
	zom = 5;
	prof = 2;
	ft_rot_x(&x, &y, -45);
	point.x = (int)floor((x * zom) + posx);
	point.y = (int)floor((y * (zom / 2)) + posy - (z * prof));
	return (point);
}

int				wiremap(void *mlx, void *win, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->x && j < map->y)
	{
		if (i < map->x - 1 && j < map->y - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], (double)i, (double)j),
					ft_vector(map->tab[j + 1][i], (double)i, (double)j + 1));
		if (j < map->y - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], (double)i, (double)j),
					ft_vector(map->tab[j][i + 1], (double)i + 1, (double)j));
		i++;
		if (i == map->x - 1 && j < map->y - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], (double)i, (double)j),
					ft_vector(map->tab[j + 1][i], (double)i, (double)j + 1));
		if (i == map->x - 1)
		{
			ft_putnbr(map->tab[j][i]);
			ft_putstr("  ");
			i = 0;
			j++;
		}
		if (j == map->y - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], (double)i, (double)j),
					ft_vector(map->tab[j][i + 1], (double)i + 1, (double)j));
	}
	return (0);
}
