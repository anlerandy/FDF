/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:17:52 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/09 14:27:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*s2;

	i = 0;
	s2 = (char*)s;
	ch = (char)c;
	while (s2[i] && ch != s2[i])
		i++;
	if (s2[i] == ch)
		return (s2 + i);
	else
		s2 = NULL;
	return (s2);
}
