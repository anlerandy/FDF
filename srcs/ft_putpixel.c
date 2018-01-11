/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:50 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/11 05:41:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void		ft_img_pixel_put(t_data **data, int x, int y)
{
	int i;

	if (x < 0 || x >= (*data)->win_w || y < 0 || y >= (*data)->win_h)
		return ;
	i = (x * 4) + (y * (*data)->frame.s_l);
	*(int*)((*data)->frame.img + i) = 0x00ffffff;
}

static int	dialex(t_coor start, t_coor end, t_data **data)
{
	double	a;
	double	b;

	a = (end.y - start.y) / (end.x - start.x);
	b = start.y - (a * start.x);
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			ft_img_pixel_put(data, start.x, start.y);
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			ft_img_pixel_put(data, start.x, start.y);
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	return (1);
}

static int	linex(t_coor start, t_coor end, t_data **data)
{
	while (start.y != end.y)
	{
		ft_img_pixel_put(data, start.x, start.y);
		(start.y > end.y ? --start.y : ++start.y);
	}
	return (1);
}

int			put_line(t_data **data, t_coor start, t_coor end)
{
	int		s_l;

	s_l = (*data)->win_h * (*data)->win_w;
	if (start.x == end.x)
		linex(start, end, data);
	else
		dialex(start, end, data);
	return (1);
}
