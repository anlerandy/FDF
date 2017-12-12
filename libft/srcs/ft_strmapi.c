/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:39:41 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 21:44:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t		i;
	char		*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = NULL;
	while (s[i++])
		if (!(ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
