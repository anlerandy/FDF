/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:42:37 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/10 10:52:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	*ptrd;
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = NULL;
	i = 0;
	ch = c;
	ptrs = ((unsigned char*)src);
	ptrd = ((unsigned char*)dst);
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrs[i] == ch)
		{
			ptrd[i] = ptrs[i];
			return (dst + i + 1);
		}
		i++;
	}
	return (ptr);
}
