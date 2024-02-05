/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_remfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/05 13:07:09 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_remfront(t_dlclst **lst, void (*del)(void *))
{
	t_dlclst	*to_remove;

	to_remove = ft_dlclst_extractfront(lst);
	if (to_remove == NULL)
		return ;
	del((void *)(to_remove->content));
	free(to_remove);
}
	/*
	t_dlclst	*new_head;

	if (*lst == NULL)
		return ;
	new_head = NULL;
	del((void *)(*lst)->content);
	if ((*lst)->next != *lst)
	{
		((*lst)->next)->prev = (*lst)->prev;
		((*lst)->prev)->next = (*lst)->next;
		new_head = (*lst)->next;
	}
	free(*lst);
	*lst = new_head;
}
*/
