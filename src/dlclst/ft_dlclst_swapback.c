/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_swapback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:48:09 by lluque            #+#    #+#             */
/*   Updated: 2024/02/03 16:33:03 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_swapback(t_dlclst **lst)
{
	t_dlclst	*shifted;

	if (*lst == NULL)
		return ;
	shifted = (*lst)->prev->prev;
	ft_dlclst_swapfront(&shifted);
	*lst = shifted->next->next;
}
