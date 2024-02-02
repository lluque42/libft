/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_rempos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/02 23:52:39 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_rempos(t_dlclst **lst, void (*del)(void *), unsigned int pos)
{
	t_dlclst		*to_be_removed;
	unsigned int	i;

	if (*lst == NULL)
		return ;
	i = 0;
	to_be_removed = *lst;
	while (i != pos)
	{
		to_be_removed = to_be_removed->next;
		i++;
	}
	del((void *)to_be_removed->content);
	to_be_removed->next->prev = to_be_removed->prev;
	to_be_removed->prev->next = to_be_removed->next;
	if (*lst == to_be_removed)
		*lst = to_be_removed->next;
	free(to_be_removed);
}
