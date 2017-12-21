/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_crafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:20:34 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/21 17:26:08 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		save_line(char **line, t_list **save)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	while ((*line)[i])
		((*line)[i] == ' ' ? a++ : a);
	if ((*map)->i == 0)
		(*map)->i = a;
	if (a == 0 || a != (*map)->i)
		return (-1);
	if (!*save)
		if (!(*save = ft_lstnew(*line, ft_strlen(*line))))
			return (-1);
	else
		save_line(line, &(*save)->next);
	return (1)
}

static void		tablines(t_map **map, t_list **save, int *rd)
{
	int			i;

	i = 0;
	if (!((*map)->tab = ft_memalloc(sizeof(int **) * (*map)->y)))
		return ((*rd = -1));
	while (i < (*map)->y && *rd == 0)
	{
		if ();
	}
}

int				coord_crafter(int fd, t_map **map)
{
	char		*line;
	t_list		*save;
	int			rd;

	rd = 0;
	line = NULL;
	save = NULL;
	*map = ft_memalloc(sizeof(t_map));
	(*map)->i = 0;
	(*map)->y = 0;
	while (rd == 1)
	{
		if ((rd = get_next_line(fd, &line)) == 1)
		{
			rd = save_line(&line, &save);
			((rd == 1) ? (*map)->y++ : ft_putendl("Erreur 01"));
		}
		(rd == 0 ? tablines(map, &save, &rd) : (rd = -1));
		if (rd == -1)
			return (-1);
	}
	ft_lstdel(&save, &ft_strdel);
	ft_strdel(&line);
	return (1);
}
