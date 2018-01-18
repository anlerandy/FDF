/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_crafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:20:34 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/18 19:19:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int		save_line(char **line, t_list **save, t_map **map)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	a = ft_count_word(*line, ' ');
	if ((*map)->x == 0)
		(*map)->x = a;
	if (a == 0 || a != (*map)->x)
		return (-1);
	if (!*save)
	{
		if (!(*save = ft_lstnew(*line, ft_strlen(*line) + 1)))
			return (-1);
	}
	else
		save_line(line, &(*save)->next, map);
	return (1);
}

static void		lineatoier(t_map **map, char **tab, int *rd, int j)
{
	int			i;

	i = 0;
	if (((*map)->tab[j] = ft_memalloc(sizeof(int) * ((*map)->x))))
		while (i < (*map)->x)
		{
			(*map)->tab[j][i] = ft_atoi(tab[i]);
			((*map)->z < ft_atoi(tab[i]) ? ((*map)->z = ft_atoi(tab[i])) : i);
			(ft_atoi(tab[i]) > ZMAX ? usage(ZMAX) : i);
			i++;
		}
	else
		*rd = -1;
	(*rd != -1 ? ft_tabdel(tab, (*map)->x) : *rd);
}

static void		tablines(t_map **map, t_list **save, int *rd)
{
	int			j;
	t_list		*tmp;
	char		*line;

	tmp = *save;
	j = 0;
	ft_putstr("Lignes (Y) lu : ");
	ft_putnbr((*map)->y);
	ft_putchar('\n');
	ft_putstr("Colonnes (X) lu : ");
	ft_putnbr((*map)->x);
	ft_putchar('\n');
	if (((*map)->tab = ft_memalloc(sizeof(int *) * ((*map)->y))))
	{
		while (tmp && *rd == 0)
		{
			line = (char *)tmp->content;
			lineatoier(map, ft_strsplit(line, ' '), rd, j);
			j++;
			tmp = tmp->next;
		}
	}
	else
		*rd = -1;
}

int				coord_crafter(int fd, t_map **map)
{
	char		*line;
	t_list		*save;
	int			rd;

	rd = 1;
	line = NULL;
	save = NULL;
	if (!(*map = ft_memalloc(sizeof(t_map))))
		return (-1);
	while (rd == 1)
		if ((rd = get_next_line(fd, &line)) == 1)
		{
			rd == 1 ? (rd = save_line(&line, &save, map)) : usage(3);
			rd == 1 ? ((*map)->y += 1) : usage(4);
			ft_strdel(&line);
		}
	rd == -1 ? usage(3) : rd;
	if (rd == -1)
		return (-1);
	rd == 0 ? tablines(map, &save, &rd) : (rd = -1);
	ft_lstdel(&save, &ft_memclr);
	return (1);
}
