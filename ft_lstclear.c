/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:51:05 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 21:13:30 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_item;
	t_list	*current_item;

	current_item = *lst;
	while (current_item != NULL)
	{
		next_item = current_item->next;
		ft_lstdelone(current_item, del);
		free(current_item);
		current_item = next_item;
	}	
}
