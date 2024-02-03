/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:38:54 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 15:48:15 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlclst_size(t_dlclst *lst)
{
	t_dlclst	*current_item;
	int			size;

	if (lst == NULL)
		return (0);
	size = 1;
	current_item = lst;
	while (current_item->next != lst)
	{
		current_item = current_item->next;
		size++;
	}
	return (size);
}
