/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/19 17:55:40 by alerandy         ###   ########.fr       */
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
	t_map	*map;

	map = NULL;
	if (ac != 2)
		return (0);
	open_map(av[1], &map);
	if (!(mlx = mlx_init()))
		return (-1);
	if (!(win = mlx_new_window(mlx, 1100, 1100, "WireCraft 0.03.3")))
		return (-1);
	wiremap(mlx, win, map);
	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx);
}
