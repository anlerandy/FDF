/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:51:59 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 21:46:29 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		size;
	char		*ptr;

	i = 0;
	size = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char*)malloc(sizeof(char) + ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[size++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[size++] = s2[i++];
	ptr[size] = '\0';
	return (ptr);
}
