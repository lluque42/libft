/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_remback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 15:46:12 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_remback(t_dlclst **lst, void (*del)(void *))
{
	t_dlclst	*new_last;

	if (*lst == NULL)
		return ;
	new_last = ((*lst)->prev)->prev;
	del((void *)(new_last->next)->content);
	free(new_last->next);
	if (new_last == *lst)
	{
		*lst = NULL;
		return ;
	}
	new_last->next = *lst;
	(*lst)->prev = new_last;
}
