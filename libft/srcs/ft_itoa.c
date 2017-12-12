/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:26:49 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 19:10:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countn(long nb)
{
	long	a;
	size_t	i;

	i = 1;
	a = 10;
	while (a - 1 < nb)
	{
		a *= 10;
		i++;
	}
	a /= 10;
	return (i);
}

static int	ft_ismill(long nb)
{
	long	a;

	a = 10;
	while (a - 1 < nb)
		a *= 10;
	a /= 10;
	return (a);
}

static long	ft_strfill(char *dst, long a, long i, long nb)
{
	while (a >= 1)
	{
		dst[i++] = nb / a + 48;
		nb %= a;
		a /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long		a;
	size_t		i;
	char		*dst;
	long		s;
	long		nb;

	nb = n;
	i = 0;
	s = 0;
	if (nb < 0)
	{
		nb = -nb;
		s++;
	}
	a = ft_countn(nb) + s;
	if (!(dst = ft_memalloc(a + 1)))
		return (NULL);
	a = ft_ismill(nb);
	if (s == 1)
		dst[i++] = '-';
	i = ft_strfill(dst, a, i, nb);
	dst[i] = '\0';
	return (dst);
}
