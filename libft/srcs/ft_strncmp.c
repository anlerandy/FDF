/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:24 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 16:04:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]
			&& n > i && s1[i] && s2[i])
		i++;
	if (i == n && ((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
		i--;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
