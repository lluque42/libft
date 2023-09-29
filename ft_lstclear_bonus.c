/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:51:05 by lluque            #+#    #+#             */
/*   Updated: 2023/09/29 16:34:34 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_item;
	t_list	*current_item;

	if (lst == NULL)
		return ;
	current_item = *lst;
	*lst = NULL;
	while (current_item != NULL)
	{
		next_item = current_item->next;
		ft_lstdelone(current_item, del);
		current_item = next_item;
	}
}
