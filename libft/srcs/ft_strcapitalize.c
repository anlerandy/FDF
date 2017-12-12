/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:45:18 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/16 14:24:05 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (!ft_isupper(s[0]) && ft_isalpha(s[0]))
			s[0] -= 32;
		else if ((ft_isspace(s[i - 1]) || !ft_isalnum(s[i - 1]))
				&& ft_isalpha(s[i]) && !ft_isupper(s[i]))
			s[i] -= 32;
		else if (ft_isalpha(s[i]) && ft_isupper(s[i]) &&
				(!ft_isspace(s[i - 1]) || ft_isalnum(s[i - 1])))
			s[i] += 32;
		i++;
	}
	return (s);
}
