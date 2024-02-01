/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_insfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:50:02 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 18:32:30 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_insfront(t_dlclst **lst, t_dlclst *new)
{
	t_dlclst	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev = new;
	}
}
