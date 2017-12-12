/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:12:24 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/10 14:53:31 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	ch;
	unsigned char	*src;

	src = (unsigned char*)s;
	i = 0;
	ptr = NULL;
	ch = c;
	while (i < n)
	{
		if (ch == src[i])
			return (ptr = src + i);
		i++;
	}
	return (ptr);
}
