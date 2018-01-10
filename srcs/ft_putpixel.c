/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:50 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 13:04:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

static int	dialex(t_coor start, t_coor end, int *img, int s_l, int width)
{
	float	a;
	float	b;
	float	pix;

	a = (end.y - start.y) / (end.x - start.x);
	b = start.y - (a * start.x);
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			if ((pix = start.x + (start.y * width)) < s_l && pix < 2147483647)
				img[abs((int)pix)] = 0xffffff;
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			if ((pix = start.x + (start.y * width)) < s_l && pix < 2147483647)
				img[abs((int)pix)] = 0xffffff;
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	ft_putnbr((int)pix);
	ft_putendl("__ 1");
	ft_putnbr(pix);
	ft_putendl("__ 2");
	if ((pix = start.x + (start.y * width)) <= s_l && pix < 2147483647)
		img[abs((int)pix)] = 0x00ffffff;
	return (1);
}

static int	linex(t_coor start, t_coor end, int *img, int s_l, int width)
{
	int		pix;

	while (start.y != end.y)
	{
		if ((pix = start.x + (start.y * width)) < s_l && pix < 2147483647)
			img[abs((int)pix)] = 0xffffff;
		(start.y > end.y ? --start.y : ++start.y);
	}
	return (1);
}

int			put_line(t_data **data, t_coor start, t_coor end)
{
	int		s_l;

	s_l = (*data)->win_h * (*data)->win_w;
	if (start.x == end.x)
		linex(start, end, (*data)->img, s_l, (*data)->win_w);
	else
		dialex(start, end, (*data)->img, s_l, (*data)->win_w);
	return (1);
}
