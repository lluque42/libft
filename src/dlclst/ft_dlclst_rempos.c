/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_rempos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/05 13:09:36 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_rempos(t_dlclst **lst, void (*del)(void *), unsigned int pos)
{
	t_dlclst	*to_remove;

	to_remove = ft_dlclst_extractpos(lst, pos);
	if (to_remove == NULL)
		return ;
	del((void *)(to_remove->content));
	free(to_remove);
}
	/*
	t_dlclst		*temp;

	temp = *lst;
	ft_dlclst_rotatenext(&temp, pos);
	ft_dlclst_remfront(&temp, del);
	ft_dlclst_rotateprev(&temp, pos);
	*lst = temp;
}
*/
