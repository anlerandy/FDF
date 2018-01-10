/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 06:26:45 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/10 22:07:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclr(void *ap, size_t len)
{
	len++;
//	ft_bzero(ap, len);
	ft_strdel((char **)&ap);
	if (ap)
		free(ap);
}
