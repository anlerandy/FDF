/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:27:33 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/09 14:32:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*s2;

	s2 = (char*)s;
	i = ft_strlen(s2);
	ch = (char)c;
	while (i > 0 && ch != s2[i])
		i--;
	if (s2[i] == ch)
		return (s2 + i);
	else
		s2 = NULL;
	return (s2);
}
