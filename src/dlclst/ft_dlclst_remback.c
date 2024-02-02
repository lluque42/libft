/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_remback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/02 23:45:15 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_remback(t_dlclst **lst, void (*del)(void *))
{
	t_dlclst	*to_be_removed;

	if (*lst == NULL)
		return ;
	to_be_removed = (*lst)->prev;
	del((void *)(to_be_removed)->content);
	to_be_removed->prev->next = *lst;
	(*lst)->prev = to_be_removed->prev;
	free(to_be_removed);
	if (*lst == to_be_removed)
	{
		*lst = NULL;
		return ;
	}
}
