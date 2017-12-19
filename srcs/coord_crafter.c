/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_crafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:20:34 by alerandy          #+#    #+#             */
/*   Updated: 2017/12/19 18:08:31 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		coord_table(t_list **save, t_map **map)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = *save;
	if (!*save)
		return (-1);
	(*map)->tab = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*map)->j = ((t_cortab *)(tmp->content))->y;
	ft_putnbr((*map)->j);
	(*map)->i = ((t_cortab *)(tmp->content))->len;
	(*map)->tab = ft_memalloc((*map)->j);
	tmp = *save;
	while (i < (*map)->j)
	{
		(*map)->tab[i] = ft_memalloc((*map)->i * sizeof(int));
		(*map)->tab[i] = ft_memcpy((*map)->tab[i],
				((t_cortab *)(tmp->content))->tab, (*map)->i * sizeof(int));
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static int		save_struct(t_list **save, t_cortab **coord)
{
	t_cortab	*verif;

	ft_putendl("Debut de la sauvegarde");
	if (!(*save))
	{
		ft_putendl("...");
		*save = ft_lstnew(*coord, sizeof(t_cortab) + (sizeof(int) * (*coord)->len));
		ft_putendl("Malloqué.");
	}
	else
	{
		verif = (*save)->content;
		ft_putnbr(verif->len);
		ft_putstr("  ?  ");
		ft_putnbr((*coord)->len);
		if (verif->len != (*coord)->len)
		{
			ft_putendl("La matrice n'est pas symétrique.\nErreur 2");
			return (-1);
		}
		(*coord)->y += 1;
		return (save_struct(&((*save)->next), coord));
	}
	ft_putendl("Vérification terminé.");
	return ((*save != NULL ? 1 : -1));
}

static int		to_struct(t_list **save, char **tab)
{
	int				i;
	int				len;
	t_cortab		*coord;

	if (!(coord = ft_memalloc(sizeof(t_cortab))))
		return (-1);
	i = 0;
	len = 0;
	coord->y = 0;
	while (tab[len] != 0)
		len++;
	coord->len = len;
	ft_putnbr(coord->len);
	coord->tab = ft_memalloc(len);
	while (len > i)
	{
		coord->tab[i] = ft_atoi(tab[i]);
		ft_putnbr(coord->tab[i]);
		ft_putendl("");
		i++;
	}
	ft_putendl("Structuration terminé.");
	return (save_struct(save, &coord));
}

static int		coord_crafter(int fd, t_map **map)
{
	char			*line;
	int				err;
	char			**tab;
	t_list			*save;

	line = NULL;
	tab = NULL;
	save = NULL;
	while ((err = get_next_line(fd, &line)) == 1)
	{
		tab = ft_strsplit(line, ' ');
		(tab != NULL ? err : (err = -1));
		(err == 1 ? err = to_struct(&save, tab) : err);
		(err == 1 ? ft_memdel((void *)tab) : ft_strdel(&line));
		(err == -1 ? ft_putendl("Erreur 5") : err);
	}
	close(fd);
	if (err == 1 || (err == 0 && save))
		return (coord_table(&save, map));
	else
		ft_putendl("La lecture du tableau a échoué.\nErreur 4");
//	if (save)
//		ft_lstdel(&save, &ft_tabdel);
	return (0);
}

int				open_map(char *arg, t_map **map)
{
	int		fd;

	fd = 0;
	*map = ft_memalloc(sizeof(t_map));
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
		exit(0);
	}
	coord_crafter(fd, map);
	ft_putnbr((*map)->tab[2][3]);
	ft_putendl("Envoi des coordonnées...");
	return (1);
}
