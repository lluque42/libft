/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:52 by lluque            #+#    #+#             */
/*   Updated: 2023/09/29 15:35:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret_val;
	t_list	*current_item;

	if (lst == NULL)
		return (0);
	ret_val = 1;
	current_item = lst;
	while (current_item->next != NULL)
	{
		ret_val++;
		current_item = current_item->next;
	}
	return (ret_val);
}
