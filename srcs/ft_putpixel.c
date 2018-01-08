/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:50 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/08 16:24:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

static int	dialex(t_coor start, t_coor end, int *img, int s_l)
{
	float	a;
	float	b;
	int		max;
	int		pix;

	a = (end.y - start.y) / (end.x - start.x);
	b = start.y - (a * start.x) + 0.5;
	max = (s_l - 1) / 4;
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			if ((pix = start.x + (start.y * 800)) < max)
				img[pix] = 0x00ffffff;
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			if ((pix = start.x + (start.y * 800)) < max)
				img[pix] = 0x00ffffff;
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	if ((pix = start.x + (start.y * 800)) < max)
		img[pix] = 0x00ffffff;
	return (1);
}

static int	linex(t_coor start, t_coor end, int *img, int s_l)
{
	int		max;
	int		pix;

	max = (s_l - 1) / 4;
	while (start.y != end.y)
	{
		if ((pix = start.x + (start.y * 800)) < max)
			img[pix] = 0x00ffffff;
		(start.y > end.y ? --start.y : ++start.y);
	}
	return (1);
}

int			put_line(t_data **data, t_coor start, t_coor end)
{
	if (start.x == end.x)
		linex(start, end, (*data)->img, (*data)->s_l);
	else
		dialex(start, end, (*data)->img, (*data)->s_l);
	return (1);
}
