/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:47:44 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 19:02:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	if (!haystack[i] || len == 0)
		return (NULL);
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i] == needle[i] && haystack[i] && i < len)
	{
		i++;
		if (i == len + 1 || !needle[i])
			return ((char*)haystack);
	}
	return (ft_strnstr(haystack + 1, needle, len - 1));
}
