/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_insfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:50:02 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 21:38:47 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_insfront(t_dlclst **lst, t_dlclst *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		((*lst)->prev)->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}
