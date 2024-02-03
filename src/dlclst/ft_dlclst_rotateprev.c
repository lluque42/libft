/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_rotateprev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:37:17 by lluque            #+#    #+#             */
/*   Updated: 2024/02/03 15:36:24 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_rotateprev(t_dlclst **lst, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (*lst == NULL)
		return ;
	while (i < n)
	{
		*lst = (*lst)->prev;
		i++;
	}
}
