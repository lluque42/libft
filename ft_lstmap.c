/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:01 by lluque            #+#    #+#             */
/*   Updated: 2023/09/18 15:10:37 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_item_original;
	t_list	*current_item_new;
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	current_item_original = lst;
	new_list = ft_lstnew(f(current_item_original->content));
	current_item_original = current_item_original->next;
	while (current_item_original != NULL)
	{
		current_item_new = ft_lstnew(f(current_item_original->content));
		ft_lstadd_back(&new_list, current_item_new);
		current_item_original = current_item_original->next;
	}
	del(NULL);
	return (new_list);
}
