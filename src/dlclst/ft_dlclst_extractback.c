/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_extractback.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/05 13:03:08 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlclst	*ft_dlclst_extractback(t_dlclst **lst)
{
	t_dlclst	*to_be_extracted;

	if (*lst == NULL)
		return (NULL);
	to_be_extracted = (*lst)->prev;
	to_be_extracted->prev->next = *lst;
	(*lst)->prev = to_be_extracted->prev;
	if (*lst == to_be_extracted)
		*lst = NULL;
	to_be_extracted->next = to_be_extracted;
	to_be_extracted->prev = to_be_extracted;
	return (to_be_extracted);
}
