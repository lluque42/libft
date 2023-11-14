/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:52:34 by lluque            #+#    #+#             */
/*   Updated: 2023/11/14 13:19:42 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_item;

	if (lst == NULL)
		return (NULL);
	current_item = lst;
	while (current_item->next != NULL)
		current_item = current_item->next;
	return (current_item);
}
