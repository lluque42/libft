/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:52 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 19:21:16 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret_val;
	t_list	*next_item;

	ret_val = 0;
	next_item = lst->next;
	while (next_item != NULL)
	{
		ret_val++;
		next_item = next_item->next;
	}
	return (ret_val);
}
