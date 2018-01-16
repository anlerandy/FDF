/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:50 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/16 09:12:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void		ft_img_pixel_put(t_data **data, int x, int y, int c)
{
	int	i;
	int	color;

	color = WHITE;
	(c == -1 ? (color = BLUE) : color);
	(c == 0 ? (color = WHITE) : color);
	(c == 1 ? (color = YELLOW) : color);
	(c == 2 ? (color = RED) : color);
	if (x < 0 || x >= (*data)->win_w || y < 0 || y >= (*data)->win_h)
		return ;
	i = (x * 4) + (y * (*data)->frame.s_l);
	*(int*)((*data)->frame.img + i) = color;
}

static int	dialex(t_coor start, t_coor end, t_data **data, int c)
{
	double	a;
	double	b;

	a = (end.y - start.y) / (end.x - start.x);
	b = start.y - (a * start.x);
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			ft_img_pixel_put(data, start.x, start.y, c);
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			ft_img_pixel_put(data, start.x, start.y, c);
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	return (1);
}

static int	linex(t_coor start, t_coor end, t_data **data, int c)
{
	while (start.y != end.y)
	{
		ft_img_pixel_put(data, start.x, start.y, c);
		(start.y > end.y ? --start.y : ++start.y);
	}
	return (1);
}

int			put_line(t_data **data, t_coor start, t_coor end)
{
	int		s_l;
	int		c;

	c = 0;
	(end.z < 0 && start.z < 0 ? (c = -1) : c);
	(end.z > (*data)->map->z / 3 && start.z > (*data)->map->z / 3 ? (c = 1)
	: c);
	(end.z > ((*data)->map->z / 3) * 2 && start.z > ((*data)->map->z / 3) * 2
	? (c = 2) : c);
	s_l = (*data)->win_h * (*data)->win_w;
	if (start.x == end.x)
		linex(start, end, data, c);
	else
		dialex(start, end, data, c);
	return (1);
}
