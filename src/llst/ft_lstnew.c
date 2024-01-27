/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:53:26 by lluque            #+#    #+#             */
/*   Updated: 2023/11/14 13:20:08 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret_val;

	ret_val = (t_list *)malloc(sizeof (t_list));
	if (ret_val == NULL)
		return (NULL);
	ret_val->content = content;
	ret_val->next = NULL;
	return (ret_val);
}
