/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:46:01 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 20:25:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr;

	if (alst)
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			*alst = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = *alst;
		}
		free(*alst);
		free(ptr);
		*alst = NULL;
		ptr = NULL;
	}
}
