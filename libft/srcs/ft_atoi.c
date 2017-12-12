/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:08:26 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/10 16:27:05 by alerandy         ###   ########.fr       */
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
	while (ft_isspace((char)str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (sign > 0)
		return (-nb);
	return (nb);
}
