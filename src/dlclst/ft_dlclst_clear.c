/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:51:05 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 20:41:00 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlclst_clear(t_dlclst **lst, void (*del)(void *))
{
	while (*lst != NULL)
	{
		ft_dlclst_remback(lst, del);
	}
}
