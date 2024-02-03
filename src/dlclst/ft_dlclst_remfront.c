/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_remfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 15:46:48 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_remfront(t_dlclst **lst, void (*del)(void *))
{
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
