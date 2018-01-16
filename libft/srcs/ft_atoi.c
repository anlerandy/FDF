/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:08:26 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/15 23:07:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		nb;
	size_t	sign;

	i = 0;
	sign = 0;
	nb = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		str[i] == '-' ? sign++ : sign;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		nb *= 10;
		nb += (str[i++] - 48);
	}
	if (sign > 0)
		return (-nb);
	return (nb);
}
