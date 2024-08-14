/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_peek_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:38:37 by lluque            #+#    #+#             */
/*   Updated: 2024/08/15 00:39:24 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlclst_peek_pos(t_dlclst *lst, unsigned int pos)
{
	unsigned int	steps;

	steps = 0;
	if (lst == NULL)
		return (NULL);
	while (steps < pos)
	{
		lst = lst->next;
		steps++;
	}
	return (lst->content);
}
