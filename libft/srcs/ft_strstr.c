/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:36:23 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/10 17:44:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	i = 0;
	if (!needle[i])
		return ((char*)haystack);
	if (!haystack[i])
		return (NULL);
	while (haystack[i] == needle[i] && haystack[i] && needle[i])
	{
		i++;
		if (!needle[i])
			return ((char*)haystack);
	}
	return (ft_strstr(haystack + 1, needle));
}
