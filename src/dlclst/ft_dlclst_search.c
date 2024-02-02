/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:01 by lluque            #+#    #+#             */
/*   Updated: 2024/02/02 14:33:02 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlclst_search(t_dlclst *lst, int (*cmp)(void *, void *), void *content)
{
	int			pos;
	int			size;

	if (lst == NULL)
		return (-1);
	pos = 0;
	size = ft_dlclst_size(lst);
	while (pos < size)
	{
		if (cmp(content, lst->content))
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}
