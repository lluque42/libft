/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_extractfront.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/05 13:02:46 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlclst	*ft_dlclst_extractfront(t_dlclst **lst)
{
	t_dlclst	*new_head;
	t_dlclst	*ret_val;

	if (*lst == NULL)
		return (NULL);
	new_head = NULL;
	if ((*lst)->next != *lst)
	{
		((*lst)->next)->prev = (*lst)->prev;
		((*lst)->prev)->next = (*lst)->next;
		new_head = (*lst)->next;
	}
	ret_val = *lst;
	*lst = new_head;
	ret_val->next = ret_val;
	ret_val->prev = ret_val;
	return (ret_val);
}
