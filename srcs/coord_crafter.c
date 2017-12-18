/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_crafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:20:34 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/18 16:17:09 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		save_struct(t_list **save, t_cortab *coord)
{
	t_cortab	*verif;

	if (!*save)
		*save = ft_lstnew(coord, sizeof(t_cortab));
	else
	{
		verif = (*save)->content;
		if (verif->len != coord->len)
		{
			ft_putendl("La matrice n'est pas symétrique.\nErreur 2");
			return (-1);
		}
		coord->y += 1;
		return (save_struct(&((*save)->next), coord));
	}
	return (*save != NULL);
}

static int		to_struct(t_list **save, char **tab)
{
	int				i;
	int				len;
	t_cortab		coord;

	i = 0;
	len = 0;
	coord.y = 0;
	while (tab[len] != 0)
		len++;
	coord.len = len;
	coord.tab = ft_memalloc(len);
	while (len > i)
	{
		coord.tab[i] = ft_atoi(tab[i]);
		i++;
	}
	return (save_struct(save, &coord));
}

static int		coord_crafter(int fd)
{
	char			*line;
	int				err;
	char			**tab;
	static t_list	*save = NULL;

	line = NULL;
	tab = NULL;
	while ((err = get_next_line(fd, &line)) == 1)
	{
		tab = ft_strsplit(line, ' ');
		(tab != NULL ? err : (err = -1));
		(err == 1 ? err = to_struct(&save, tab) : err);
		(err == 1 ? ft_memdel((void *)tab) : ft_strdel(&line));
	}
	return (err);
}

int				open_map(char *arg)
{
	int		fd;

	fd = 0;
	if (arg)
		fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		if (arg)
		{
			ft_putstr("Échec d'ouverture de ");
			ft_putendl(arg);
		}
		else
			ft_putendl("Échec création de matrice depuis l'entrée standard.");
		ft_putendl("Erreur 3");
		return (-1);
	}
	return (coord_crafter(fd));
}
