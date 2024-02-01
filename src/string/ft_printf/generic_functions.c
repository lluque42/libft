/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:39:26 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:54:51 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

int	has_flag(t_flags flags_word, t_flags flag)
{
	return (flags_word & flag);
}

void	set_flag(t_flags *flags_word, t_flags flag)
{
	*flags_word = *flags_word | flag;
}

int	free_and_return_value(void *pointer, int ret_value)
{
	free(pointer);
	return (ret_value);
}
