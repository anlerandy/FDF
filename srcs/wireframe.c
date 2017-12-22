/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:17:33 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/22 02:20:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

static int	dialage(void *mlx, void *win, t_coor start, t_coor end)
{
	float	a;
	float	b;

	a = (end.y - start.y) / (end.x - start.x);
	b = start.y - (a * start.x) + 0.5;
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			mlx_pixel_put(mlx, win, start.x, start.y, 0xffffff);
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			mlx_pixel_put(mlx, win, start.x, start.y, 0xffffff);
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	mlx_pixel_put(mlx, win, start.x, start.y, 0xffffff);
	return (1);
}

static int	lineage(void *mlx, void *win, t_coor start, t_coor end)
{
	while (start.y != end.y)
	{
		mlx_pixel_put(mlx, win, start.x, start.y, 0x5000ff00);
		(start.y > end.y ? --start.y : ++start.y);
	}
	return (1);
}

int			draw_line(t_data **data, t_coor start, t_coor end)
{
	if (start.x == end.x)
		lineage((*data)->mlx, (*data)->win, start, end);
	else
		dialage((*data)->mlx, (*data)->win, start, end);
	return (1);
}
