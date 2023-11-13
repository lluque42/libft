/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:50:02 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 19:43:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_item;

	if (new == NULL || lst == NULL)
		return ;
	current_item = ft_lstlast(*lst);
	if (current_item == NULL)
	{
		*lst = new;
		return ;
	}
	current_item->next = new;
}
