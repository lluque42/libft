/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst_inspos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:45 by lluque            #+#    #+#             */
/*   Updated: 2024/02/03 16:33:47 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclst_inspos(t_dlclst **lst, t_dlclst *new, unsigned int pos)
{
	t_dlclst	*temp;

	temp = *lst;
	ft_dlclst_rotatenext(&temp, pos);
	ft_dlclst_insfront(&temp, new);
	ft_dlclst_rotateprev(&temp, pos);
	*lst = temp;
}
