/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 23:06:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	ft_input(t_data *data)
{
	wiremap(&data, data->map);
	mlx_loop_hook(data->mlx, ft_infinrot, (void*)data);
	mlx_key_hook(data->win, ft_exit, (void *)data);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

static int	*ft_intset(int *tab, int i, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		tab[x] = i;
		x++;
	}
	return (tab);
}

static int	set_data(t_data *data)
{
	data->posx = data->win_w / 3;
	data->posy = data->win_h / 2;
	data->zoom = 1;
	data->depth = 1;
	data->map = NULL;
	data->rotx = 60;
	data->roty = 15;
	return (0);
}

int			main(int ac, char **av)
{
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	data->win_w = ac == 4 ? ft_atoi(av[2]) : 1100;
	data->win_h = ac == 4 ? ft_atoi(av[3]) : 1100;
	set_data(data);
	if (ac > 4 && ac < 2)
		return (-1);
	(data->fd = open(av[1], O_RDONLY)) == -1 ? exit(0) : ft_putendl("FD done");
	((coord_crafter(data->fd, &(data->map)) != 1) ? exit(0) : data->fd);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, WIN)))
		return (-1);
	data->pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->img = (int *)mlx_get_data_addr(data->pimg, &(data->bpp),
			&(data->s_l), &(data->ndia));
	data->img = ft_intset(data->img, 0x0f000000, data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
