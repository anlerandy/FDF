/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:04:04 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/16 01:06:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tabdel(char **tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_strdel(&tab[i]);
		tab[i++] = NULL;
	}
	free(*tab);
	free(tab);
	tab = NULL;
}
