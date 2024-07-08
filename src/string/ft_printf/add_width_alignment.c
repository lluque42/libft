/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_alignment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:45:53 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:45:34 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

// A new forced strlen will be added to properly support %c NUL char conversions
int	ft_printf_add_width_alignment(t_format *format, char **str)
{
	char	*new_str;
	int		ret_val;

	if (ft_strlen(*str) >= format->width)
		return (1);
	new_str = malloc((format->width + 1) * sizeof (char));
	if (new_str == NULL)
		return (0);
	if (ft_printf_has_flag(format->flags, LEFT_JUSTIFY))
		ret_val = ft_printf_left_case(format, str, new_str);
	else
		ret_val = ft_printf_right_case(format, str, new_str);
	return (ret_val);
}
