/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_peek_offset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:37:33 by lluque            #+#    #+#             */
/*   Updated: 2024/08/15 00:55:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlclst_peek_offset(t_dlclst *head, int offset)
{
	long	steps;
	long	stop;

	if (head == NULL)
		return (NULL);
	if (ft_dlclst_size(head) < 2 && ft_abs(offset) == 1)
		return (NULL);
	steps = 0;
	stop = ft_abs(offset);
	while (steps < stop)
	{
		if (offset > 0)
			head = head->next;
		else
			head = head->prev;
		steps++;
	}
	return (head->content);
}
