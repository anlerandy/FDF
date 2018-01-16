/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:23:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/16 10:18:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *str, char c)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			a++;
			i++;
		}
	}
	return (a);
}

static size_t	ft_count_word(char const *str, char c)
{
	size_t	a;
	size_t	s;
	size_t	i;

	a = 0;
	i = 0;
	s = 0;
	while (str[a])
	{
		if (str[a] != c)
		{
			if (s == 0)
			{
				i++;
				s++;
			}
			a++;
		}
		else
		{
			a++;
			s = 0;
		}
	}
	return (i);
}

static char		**ft_tab_addr(char *nstr, char const *str, char c)
{
	char	**tab;
	size_t	a;
	size_t	j;
	int		i;

	j = 0;
	i = 0;
	a = ft_count_word(str, c);
	if (!(tab = ft_memalloc(sizeof(char*) * (a + 1))))
		return (NULL);
	if (a == 0)
	{
		tab[0] = 0;
		return (tab);
	}
	while (j < a)
	{
		tab[j] = ft_strnew(ft_strlen(nstr + i) + 1);
		ft_strcpy(tab[j], nstr + i);
		i = i + ft_strlen(nstr + i) + 1;
		j++;
	}
	tab[j] = 0;
	free(nstr);
	return (tab);
}

static char		*ft_n_long_str(char const *s, char *nstr, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nstr[j++] = s[i++];
			if (s[i] == c)
			{
				nstr[j] = '\0';
				j++;
			}
			nstr[j] = '\0';
		}
		else
			i++;
	}
	return (nstr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*nstr;
	size_t	j;

	if (!s)
		return (0);
	j = ft_count(s, c) + ft_count_word(s, c);
	if (!(nstr = ft_memalloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	nstr = ft_n_long_str(s, nstr, c);
	return (ft_tab_addr(nstr, s, c));
}
