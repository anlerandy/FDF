/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wired_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:37:16 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/21 21:31:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coor	ft_vector(int z, int x, int y)
{
	t_coor		point;

	point.x = ((x - (y)) * 30) + 300;
	point.y = (((x + (y)) * 15) + 300) - (z * 15);
	return (point);
}

int				wiremap(void *mlx, void *win, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->x - 1 && j < map->y - 1)
	{
		if (i < map->x - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], i, j),
					ft_vector(map->tab[j + 1][i], i, j + 1));
		if (j < map->y - 1)
			draw_line(mlx, win, ft_vector(map->tab[j][i], i, j),
					ft_vector(map->tab[j][i + 1], i + 1, j));
		i++;
		if (i >= map->x - 1)
		{
			i = 0;
			j++;
		}
	}
	return (0);
}
