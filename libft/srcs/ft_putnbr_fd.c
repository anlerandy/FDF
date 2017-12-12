/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:07:47 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/11 21:08:18 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
	while (a >= 1)
	{
		ft_putchar_fd(nbr / a + 48, fd);
		nbr %= a;
		a /= 10;
	}
}
