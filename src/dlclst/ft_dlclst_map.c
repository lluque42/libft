/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:01 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 22:53:35 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_stuff(void **content, t_dlclst **lst, void (*del)(void *))
{
	del((*content));
	ft_dlclst_clear(lst, del);
	return (NULL);
}

t_dlclst	*ft_dlclst_map(t_dlclst *l, void *(*f)(void *), void (*d)(void *))
{
	t_dlclst	*new_lst_item;
	t_dlclst	*new_list;
	t_dlclst	*original_list;
	void		*new_content;

	if (l == NULL)
		return (NULL);
	new_list = NULL;
	original_list = l;
	while (1)
	{
		new_content = f(l->content);
		if (new_content == NULL)
			return (free_stuff(&new_content, &new_list, d));
		new_lst_item = ft_dlclst_new(new_content);
		if (new_lst_item == NULL)
			return (free_stuff(&new_content, &new_list, d));
		ft_dlclst_insback(&new_list, new_lst_item);
		if (original_list == l->next)
			break ;
		l = l->next;
	}
	return (new_list);
}
