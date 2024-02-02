/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_inspos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:45 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 22:21:20 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_inspos(t_dlclst **lst, t_dlclst *new, unsigned int pos)
{
	t_dlclst	*to_be_shifted;
	int			i;

	if (*lst == NULL)
		*lst = new;
	else
	{
		i = 0;
		to_be_shifted = *lst;
		while (i != pos)
		{
			to_be_shifted = to_be_shifted->next;
			ft_printf("i = %d\n", i);
			i++;
		}
		new->next = to_be_shifted;
		new->prev = to_be_shifted->prev;
		to_be_shifted->prev->next = new;
		to_be_shifted->prev = new;
		if (to_be_shifted == *lst)
			*lst = (*lst)->prev;
	}
}
