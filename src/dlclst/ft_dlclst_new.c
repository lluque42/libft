/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:26 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 15:44:15 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlclst	*ft_dlclst_new(void *content)
{
	t_dlclst	*ret_val;

	ret_val = (t_dlclst *)malloc(sizeof (t_dlclst));
	if (ret_val == NULL)
		return (NULL);
	ret_val->content = content;
	ret_val->prev = ret_val;
	ret_val->next = ret_val;
	return (ret_val);
}
