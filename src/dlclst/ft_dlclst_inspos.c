/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_inspos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:45 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 18:32:42 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_inspos(t_dlclst **lst, t_dlclst *new, unsigned int pos)
{
	t_dlclst	*current_item;
	int			i;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		i = 0;
		current_item = *lst;
		while (i != pos)
		{
			current_item = current_item->next;
			i++;
		}
		new->next = current_item;
		new->prev = current_item->prev;
		current_item->prev = new;
		if (current_item == *lst)
			*lst = new;
	}
}
