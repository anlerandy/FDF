/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:15:29 by alerandy          #+#    #+#             */
/*   Updated: 2017/11/15 20:45:32 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list		*nlst;
	t_list		*ptr;
	t_list		*nptr;

	if (!lst)
		return (NULL);
	if (!(nlst = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	ptr = lst->next;
	nptr = nlst;
	while (ptr != NULL)
	{
		if ((nptr->next = f(ft_lstnew(ptr->content, ptr->content_size))))
			nptr = nptr->next;
		ptr = ptr->next;
	}
	nptr->next = NULL;
	return (nlst);
}
