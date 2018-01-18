/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/18 19:29:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	ft_input(t_data *data)
{
	data->frame.img = ft_intset(data->frame.img, BLUR,
			data->win_w * data->win_h);
	wiremap2(&data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	mlx_loop_hook(data->mlx, ft_infinrot, (void*)data);
	mlx_hook(data->win, 2, 0, ft_exit, (void *)data);
	mlx_hook(data->win, 17, 0, ft_close, 0);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

char		*ft_intset(char *tab, int i, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		((int*)tab)[x] = i;
		x++;
	}
	return (tab);
}

static void	set_data(t_data *data, int ac, char **av)
{
	if (ac == 4)
	{
		data->win_w = ft_atoi(av[2]) < 100 ? 1100 : ft_atoi(av[2]);
		data->win_h = ft_atoi(av[3]) < 100 ? data->win_w : ft_atoi(av[3]);
	}
	else
	{
		data->win_w = 1100;
		data->win_h = 1100;
	}
	data->posx = data->win_w / 3;
	data->posy = data->win_h / 2;
	data->zoom = 2;
	data->depth = 1;
	data->rotx = 45;
	data->roty = 0;
	data->rotz = -60;
}

void		usage(int err)
{
	if (err == 1)
	{
		ft_putendl("Arguments incorrectes : - ./fdf [file] (width height)");
		ft_putendl("\t\t\tEx. : ./fdf test_maps/42.fdf 2555 1390");
		ft_putendl("NB :\twidth cannot exceed 2555 and be less than 100");
		ft_putendl("\theight cannot exceed 1390 and be less than 100\n");
	}
	if (err == 2)
		ft_putendl("File is missing.\n");
	if (err == 3)
		ft_putendl("File is not a supported file : text file or .fdf only.\n");
	if (err == 4)
	{
		ft_putstr("File is not valid : ");
		ft_putendl("must contain a constant size along the lines.\n");
	}
	if (err == ZMAX)
		ft_putendl("\nFile contain a z coordonate too high.\nMax : 5'000.\n");
	exit(0);
}

int			main(int ac, char **av)
{
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	set_data(data, ac, av);
	if (ac > 4 || ac < 2)
		usage(1);
	(data->fd = open(av[1], O_RDONLY)) == -1 ? usage(2) : ft_putstr("Reading ");
	data->fd != -1 ? ft_putendl(av[1]) : ft_putstr("");
	((coord_crafter(data->fd, &data->map) != 1) ? exit(0) : data->fd);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, WIN)))
		return (-1);
	data->frame.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->frame.img = mlx_get_data_addr(data->frame.pimg, &(data->frame.bpp),
			&(data->frame.s_l), &(data->frame.ndia));
	data->frame.img = ft_intset(data->frame.img, BLUR,
			data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
