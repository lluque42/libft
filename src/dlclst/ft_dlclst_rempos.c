/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_rempos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 21:59:21 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_rempos(t_dlclst **lst, void (*del)(void *), unsigned int pos)
{
	t_dlclst	*to_be_deleted;
	int			i;

	if (*lst == NULL)
		return ;
	i = 0;
	to_be_deleted = *lst;
	while (i != pos)
	{
		to_be_deleted = to_be_deleted->next;
		i++;
	}
	del((void *)to_be_deleted->content);
	(to_be_deleted->next)->prev = to_be_deleted->prev;
	(to_be_deleted->prev)->next = to_be_deleted->next;
	if (*lst == to_be_deleted)
		*lst = to_be_deleted->next;
	free(to_be_deleted);
}
