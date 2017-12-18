/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/18 22:12:48 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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
	if (!(win = mlx_new_window(mlx, 500, 500, "WireCraft 0.03")))
		return (-1);
	draw_line(mlx, win, start, end);
	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx);
}
