/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_rempos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 15:47:52 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_rempos(t_dlclst **lst, void (*del)(void *), unsigned int pos)
{
	t_dlclst	*temp;
	int			i;

	if (*lst == NULL)
		return ;
	i = 0;
	temp = *lst;
	while (i != pos)
		temp = temp->next;
	del((void *)temp->content);
	(temp->next)->prev = temp->prev;
	(temp->prev)->next = temp->next;
	free(temp);
	if (*lst == temp)
		*lst = NULL;
}
