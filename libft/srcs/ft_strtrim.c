/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:57:18 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 20:40:25 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		a;
	char		*ptr;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	a = ft_strlen(s);
	while (ft_isspace(s[i]) == 1)
		i++;
	while (ft_isspace(s[a - 1]) == 1 && a > i)
		a--;
	ptr = (char*)malloc(sizeof(char) * (a - i) + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && i < a)
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	return (ptr);
}
