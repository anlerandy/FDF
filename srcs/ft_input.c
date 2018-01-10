/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:53:12 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 12:41:15 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_exit(int key, void *param)
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
	key == 89 ? data->depth += 1 : key;
	if (key == 83 && data->depth > -10)
		data->depth -= 1;
	key == 85 ? (data->flag = (data->flag + 1) % 2) : key;
	mlx_put_image_to_window(NULL, data->win, (char*)data->pimg, 0, 0);
//	wiremap(&data, (data)->map);
	ft_putstr("\nKeycode = ");
	ft_putnbr(key);
	return (0);
}
