/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:01 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 19:43:14 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_stuff(void **content, t_list **lst, void (*del)(void *))
{
	del((*content));
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*original_lst;
	t_list	*new_lst_item;
	t_list	*new_list;
	void	*new_content;

	if (lst == NULL)
		return (NULL);
	original_lst = lst;
	new_list = NULL;
	while (lst != NULL)
	{	
		new_content = f(lst->content);
		if (new_content == NULL)
			return (free_stuff(&new_content, &new_list, del));
		new_lst_item = ft_lstnew(new_content);
		if (new_lst_item == NULL)
			return (free_stuff(&new_content, &new_list, del));
		ft_lstadd_back(&new_list, new_lst_item);
		lst = lst->next;
	}
	return (new_list);
}
