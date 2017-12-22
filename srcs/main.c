/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/22 05:28:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	ft_exit(int key, void *param)
{
	t_data *data;

	key == 53 ? exit(0) : key;
	data = (t_data *)param;
	if (key == 69 || key == 24)
		data->zoom *= 1.8;
	if ((key == 78 || key == 27) && (data)->zoom > 1)
		data->zoom = data->zoom / 1.8;
	key == 123 ? data->posx -= 10 : key;
	key == 124 ? data->posx += 10 : key;
	key == 126 ? data->posy -= 10 : key;
	key == 125 ? data->posy += 10 : key;
	key == 86 ? data->rotx += 15 : key;
	key == 88 ? data->rotx -= 15 : key;
	key == 89 ? data->depth  += 1 : key;
	if (key == 83 && data->depth > -10)
		data->depth  -= 1;
	key == 85 ? (data->flag = (data->flag + 1) % 2) : key;
	mlx_put_image_to_window(NULL, data->win, (char*)data->pimg, 0, 0);
	wiremap(&data, (data)->map);
	ft_putstr("\nKeycode = ");
	ft_putnbr(key);
	return (0);
}

static	int	ft_infrot(void *param)
{
	t_data *data;

	data = (t_data*)param;
	if (data->flag)
		data->rotx++;
	mlx_put_image_to_window(NULL, data->win, (char*)data->pimg, 0, 0);
	wiremap(&data, (data)->map);
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
		data->zoom *= 1.1;
	}
	if (key == 4 && (data)->zoom > 1)
		data->zoom = data->zoom / 1.1;
	mlx_put_image_to_window(NULL, data->win, (char*)data->pimg, 0, 0);
	wiremap(&data, (data)->map);
	return (0);
}

static void	ft_input(t_data *data)
{
	wiremap(&data, data->map);
	mlx_loop_hook(data->mlx, ft_infrot, (void*)data);
	mlx_key_hook(data->win, ft_exit, (void *)data);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

int			*ft_intset(int	*tab, int i, int size)
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
	data->posx = data->win_w / 3;
	data->posy = data->win_h / 3;
	data->zoom = 1;
	data->depth = 1;
	data->rotx = 0;
	data->flag = 0;
	data->map = NULL;
	if (ac > 4 && ac < 2)
		return (-1);
	(data->fd = open(av[1], O_RDONLY)) == -1 ? exit(0) : ft_putendl("FD done");
	if (coord_crafter(data->fd, &(data->map)) != 1)
		exit(0);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, WIN)))
		return (-1);
	data->pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->img = (int *)mlx_get_data_addr(data->pimg, &(data->bpp), &(data->s_l), &(data->ndia));
	data->img = ft_intset(data->img, 0xd5000000, data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
