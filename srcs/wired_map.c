/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wired_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:37:16 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/22 04:54:03 by alerandy         ###   ########.fr       */
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
	*x = (((double)*x * cos(teta)) - ((double)*y * sin(teta)));
	*y = ((xtmp * sin(teta)) + ((double)*y * cos(teta)));
}

static t_coor	ft_vector(double z, double x, double y, t_data **data)
{
	t_coor		point;

	ft_rot_x(&x, &y, (*data)->rotx);
	point.x = (int)floor((x * (*data)->zoom) + (*data)->posx);
	point.y = (int)floor((y * ((*data)->zoom / 2)) + (*data)->posy -
			(z * (*data)->depth));
	return (point);
}

int				wiremap(t_data **data, t_map *map)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while ((int)i < map->x && (int)j < map->y)
	{
		if ((int)i < map->x - 1 && (int)j < map->y - 1)
			draw_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j + 1][(int)i], i, j + 1, data));
		if (j < map->y - 1)
			draw_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j][(int)i + 1], i + 1, j, data));
		i++;
		if ((int)i == map->x - 1 && (int)j < map->y - 1)
			draw_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j + 1][(int)i], i, j + 1, data));
		if ((int)i == map->x - 1)
		{
			i = 0;
			j++;
		}
		if ((int)j == map->y - 1)
			draw_line(data, ft_vector(map->tab[(int)j][(int)i], i, j, data),
					ft_vector(map->tab[(int)j][(int)i + 1], i + 1, j, data));
	}
	return (0);
}
