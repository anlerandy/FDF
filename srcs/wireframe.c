/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:17:33 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/15 23:16:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		ft_rot_z(double *x, double *y, double a)
{
	double		teta;
	double		xtmp;

	xtmp = *x;
	teta = a * ((2 * M_PI) / 360);
	*x = (*x * cos(teta)) - (*y * sin(teta));
	*y = (xtmp * sin(teta)) + (*y * cos(teta));
}

static void		ft_rot_x(double *y, double *z, double a)
{
	double		teta;
	double		ztmp;

	ztmp = *z;
	teta = a * ((2 * M_PI) / 360);
	*z = (sin(teta) * *y) + (cos(teta) * *z);
	*y = (cos(teta) * *y) - (sin(teta) * ztmp);
}

static void		ft_rot_y(double *x, double *z, double a)
{
	double		teta;
	double		ztmp;

	ztmp = *z;
	teta = a * ((2 * M_PI) / 360);
	*z = (sin(teta) * *x) - (cos(teta) * *z);
	*x = (cos(teta) * *x) + (sin(teta) * ztmp);
}

static t_coor	ft_vector(double z, double x, double y, t_data **data)
{
	t_coor		point;

	point.z = z;
	z = z * (*data)->depth;
	ft_rot_z(&x, &y, (*data)->rotz);
	ft_rot_x(&y, &z, (*data)->rotx);
	ft_rot_y(&x, &z, (*data)->roty);
	point.x = floor((x * (*data)->zoom) + (*data)->posx);
	point.y = floor((y * ((*data)->zoom)) + (*data)->posy);
	return (point);
}

int				wiremap2(t_data **data, t_map *map)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while ((int)i < map->x && (int)j < map->y)
	{
		if ((int)i < map->x - 1 && (int)j < map->y - 1)
			put_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j + 1][(int)i], i, j + 1, data));
		if (j < map->y - 1)
			put_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j][(int)i + 1], i + 1, j, data));
		i++;
		if ((int)i == map->x - 1 && (int)j < map->y - 1)
			put_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j + 1][(int)i], i, j + 1, data));
		((int)i == map->x - 1 ? j++ : i);
		((int)i == map->x - 1 ? (i = 0) : i);
		if ((int)j == map->y - 1)
			put_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j][(int)i + 1], i + 1, j, data));
	}
	return (0);
}
