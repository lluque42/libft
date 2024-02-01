/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:10:17 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 18:35:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlclst	*ft_dlclst_last(t_dlclst *lst)
{
	if (lst == NULL)
		return (NULL);
	return (lst->prev);
}
