/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 18:47:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static	int	ft_infinrot(void *param)
{
	t_data *data;

	data = (t_data*)param;
	if (data->flag)
		data->rotx = (int)(data->rotx + 1) % 360;
	mlx_put_image_to_window(NULL, data->win, (char*)data->pimg, 0, 0);
	data->img = ft_intset(data->img, 0xd5000000, data->win_w * data->win_h);
	wiremap2(&data, (data)->map);
	return (1);
}

static int	ft_zoom(int key, int x, int y, void *param)
{
	t_data *data;

	x = 0;
	y = 0;
	data = (t_data *)param;
	if (key == 5)
	{
		ft_putnbr((int)data->zoom);
		data->zoom *= 2;
	}
	if (key == 4 && (data)->zoom > 1)
		data->zoom = data->zoom / 2;
	data->img = ft_intset(data->img, 0xd5000000, data->win_w * data->win_h);
	wiremap2(&data, (data)->map);
	return (0);
}

static void	ft_input(t_data *data)
{
	data->img = ft_intset(data->img, 0xd5000000, data->win_w * data->win_h);
	wiremap2(&data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, (char*)data->pimg, 0, 0);
	mlx_loop_hook(data->mlx, ft_infinrot, (void*)data);
	mlx_key_hook(data->win, ft_exit, (void *)data);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

int			*ft_intset(int *tab, int i, int size)
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

int			main(int ac, char **av)
{
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	data->win_w = ac == 4 ? ft_atoi(av[2]) : 1100;
	data->win_h = ac == 4 ? ft_atoi(av[3]) : 1100;
	data->posx = data->win_w / 2;
	data->posy = data->win_h / 2;
	data->zoom = 1;
	data->depth = 1;
	data->map = NULL;
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
	data->img = ft_intset(data->img, 0xd5000000, data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
