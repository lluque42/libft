/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_insback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:50:02 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 18:31:56 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_insback(t_dlclst **lst, t_dlclst *new)
{
	t_dlclst	*former_last;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		former_last = (*lst)->prev;
		(*lst)->prev = new;
		former_last->next = new;
	}
}
