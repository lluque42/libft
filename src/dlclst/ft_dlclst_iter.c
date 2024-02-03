/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:52:08 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 20:53:12 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_iter(t_dlclst *lst, void (*f)(void *))
{
	t_dlclst	*current_item;

	current_item = lst;
	f(current_item->content);
	current_item = current_item->next;
	while (current_item != lst)
	{
		f(current_item->content);
		current_item = current_item->next;
	}
}
