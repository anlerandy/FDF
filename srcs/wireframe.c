/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:17:33 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/14 18:16:21 by alerandy         ###   ########.fr       */
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
	b = start.y - (a * start.x) + 0.5; //Le + 0.5 permet de rendre la ligne plus jolie.
	if (fabs(a) < 1)
		while (start.x != end.x)
		{
			mlx_pixel_put(mlx, win, start.x, start.y, 0x5000ff00);
			(start.x > end.x ? --start.x : ++start.x);
			start.y = (a * start.x) + b;
		}
	else
		while (start.y != end.y)
		{
			mlx_pixel_put(mlx, win, start.x, start.y, 0x500000ff);
			(start.y > end.y ? --start.y : ++start.y);
			start.x = (start.y - b) / a;
		}
	mlx_pixel_put(mlx, win, start.x, start.y, 0x5000ff00);
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

static int	ft_exit(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_coor	start;
	t_coor	end;

	if (ac != 5)
		return (0);
	start.x = ft_atoi(av[1]);
	start.y = ft_atoi(av[2]);
	start.z = 0;
	end.x = ft_atoi(av[3]);
	end.y = ft_atoi(av[4]);
	end.z = 0;
	if (!(mlx = mlx_init()))
		return (-1);
	if (!(win = mlx_new_window(mlx, 500, 500, "WireCraft 0.01")))
		return (-1);
	if (start.x == end.x)
		lineage(mlx, win, start, end);
	else
		dialage(mlx, win, start, end);
	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx);
}
