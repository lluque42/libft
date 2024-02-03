/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_swapfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:48:09 by lluque            #+#    #+#             */
/*   Updated: 2024/02/03 10:57:36 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_swapfront(t_dlclst **lst)
{
	t_dlclst	*temp1;
	t_dlclst	*temp2;

	if (*lst == NULL)
		return ;
	if ((*lst)->next->next == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	(*lst)->next->next->prev = *lst;
	temp2 = (*lst)->next->next;
	(*lst)->next->next = *lst;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	temp1 = (*lst)->next;
	(*lst)->next = temp2;
	(*lst)->prev = temp1;
	*lst = (*lst)->prev;
}
