/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_crafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:20:34 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/18 22:07:56 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		**coord_table(t_list **save)
{
	int			**tab;
	t_list		*tmp;
	int			y;
	int			len;
	int			i;

	i = 0;
	tmp = *save;
	tab = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	y = ((t_cortab *)(tmp->content))->y;
	len = ((t_cortab *)(tmp->content))->len;
	tab = ft_memalloc(y);
	tmp = *save;
	while (i < y)
	{
		tab[i] = ft_memalloc(len * sizeof(int));
		tab[i] = ft_memcpy(tab[i], ((t_cortab *)(tmp->content))->tab,
				len * sizeof(int));
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

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

static int		**coord_crafter(int fd)
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
	if (err == 1)
		return (coord_table(&save));
	else
		ft_putendl("La lecture du tableau a échoué.\nErreur 4");
	ft_lstdel(&(save), &ft_tabdel);
	return (NULL);
}

int				**open_map(char *arg)
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
		return (NULL);
	}
	return (coord_crafter(fd));
}
