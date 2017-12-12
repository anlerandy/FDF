/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:44:05 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/11 21:00:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long			a;
	long			nbr;
	size_t			sign;

	nbr = n;
	sign = 0;
	a = 10;
	if (n < 0)
	{
		nbr = -nbr;
		sign++;
	}
	while (a - 1 < nbr)
		a *= 10;
	a /= 10;
	if (sign > 0)
		ft_putchar('-');
	while (a >= 1)
	{
		ft_putchar(nbr / a + 48);
		nbr %= a;
		a /= 10;
	}
}
