/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:55:34 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 16:12:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	expt;

	a = 0;
	i = ft_strlen(dst);
	expt = i + ft_strlen(src);
	if (size < i)
		return (size + expt - i);
	if (size < expt + 1)
		while (src[a] && i < size - 1)
			dst[i++] = src[a++];
	else
		while (src[a] && i < size)
			dst[i++] = src[a++];
	dst[i] = '\0';
	return (expt);
}
