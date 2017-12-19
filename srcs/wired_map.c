/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wired_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:37:16 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/19 18:26:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coor	ft_vector(int z, int x, int y)
{
	t_coor		point;

	point.x = (y + x) * 10;
	point.y = ((x + y) * 5) - z;
	return (point);
}

int				wiremap(void *mlx, void *win, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putnbr(map->tab[2][3]);
	while (i < map->i && j < map->j)
	{
		if (i < map->i - 1)
			draw_line(mlx, win, ft_vector(map->tab[i][j], i, j),
					ft_vector(map->tab[i + 1][j], i + 1, j));
		if (j < map->j - 1)
			draw_line(mlx, win, ft_vector(map->tab[i][j], i, j),
					ft_vector(map->tab[i][j + 1], i, j + 1));
		i++;
		if (i >= map->i)
		{
			i = 0;
			j++;
		}
	}
	return (0);
}
