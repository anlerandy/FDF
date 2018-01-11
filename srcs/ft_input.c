/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:53:12 by alerandy          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/01/10 23:33:36 by alerandy         ###   ########.fr       */
=======
/*   Updated: 2018/01/11 05:51:55 by alerandy         ###   ########.fr       */
>>>>>>> images
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int		ft_rot_input(int key, t_data *data)
{
	key == 91 ? data->rotx = (int)(data->rotx + 15) % 360 : key;
	key == 87 ? data->rotx = (int)(data->rotx - 15) % 360 : key;
	key == 86 ? data->roty = (int)(data->roty + 15) % 360 : key;
	key == 88 ? data->roty = (int)(data->roty - 15) % 360 : key;
	key == 92 ? data->rotz = (int)(data->rotz + 15) % 360 : key;
	key == 85 ? data->rotz = (int)(data->rotz - 15) % 360 : key;
	return (0);
}

int				ft_infinrot(void *param)
{
	t_data *data;

	data = (t_data*)param;
	if (data->flag)
		data->rotx = (int)(data->rotx + 1) % 360;
	if (data->flag2)
		data->roty = (int)(data->roty + 1) % 360;
	mlx_put_image_to_window(NULL, data->win, (char*)data->frame.pimg, 0, 0);
	data->frame.img = ft_intset(data->frame.img, BLUR,
			data->win_w * data->win_h);
	wiremap2(&data, (data)->map);
	return (1);
}

int				ft_zoom(int key, int x, int y, void *param)
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
	data->frame.img = ft_intset(data->frame.img, BLUR,
			data->win_w * data->win_h);
	wiremap2(&data, (data)->map);
	return (0);
}

int				ft_exit(int key, void *param)
{
	t_data *data;

	key == 53 ? exit(0) : key;
	data = (t_data *)param;
	if (key == 69 || key == 24)
		data->zoom *= 2;
	if ((key == 78 || key == 27) && (data)->zoom > 1)
		data->zoom = data->zoom / 2;
	key == 123 ? data->posx -= 10 * (data->zoom / 2) : key;
	key == 124 ? data->posx += 10 * (data->zoom / 2) : key;
	key == 126 ? data->posy -= 10 * (data->zoom / 2) : key;
	key == 125 ? data->posy += 10 * (data->zoom / 2) : key;
	key == 89 ? data->depth += 1 : key;
	if (key == 83 && data->depth > -10)
		data->depth -= 1;
	ft_rot_input(key, data);
	key == 82 ? (data->flag = (data->flag + 1) % 2) : key;
	key == 65 ? (data->flag2 = (data->flag2 + 1) % 2) : key;
	ft_putstr("\nKeycode = ");
	ft_putnbr(key);
	return (0);
}
