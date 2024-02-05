/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_extractpos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:58 by lluque            #+#    #+#             */
/*   Updated: 2024/02/05 12:56:37 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlclst	*ft_dlclst_extractpos(t_dlclst **lst, unsigned int pos)
{
	t_dlclst	*temp;
	t_dlclst	*ret_val;

	temp = *lst;
	ft_dlclst_rotatenext(&temp, pos);
	ret_val = ft_dlclst_extractfront(&temp);
	ft_dlclst_rotateprev(&temp, pos);
	*lst = temp;
	return (ret_val);
}
