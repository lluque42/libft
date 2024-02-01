/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_alignment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:45:53 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:51:23 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

// For right-justify alignment and zero padding of conversions which support it
void	leading_ack(t_format *format, int *original_sign, int *prefix);

// For right-justify zero padding of conversions which support it
int		right_zero_case(t_format *format, char **str, char *new_str);

// For right-justify space padding
int		right_space_case(t_format *format, char **str, char *new_str);

// For right-justify
int		right_case(t_format *format, char **str, char *new_str);

// For left-justify, only applies space-padding.
int		left_case(t_format *format, char **str, char *new_str);

// A new forced strlen will be added to properly support %c NUL char conversions
int	add_width_alignment(t_format *format, char **str)
{
	char	*new_str;
	int		ret_val;

	if (ft_strlen(*str) >= format->width)
		return (1);
	new_str = malloc((format->width + 1) * sizeof (char));
	if (new_str == NULL)
		return (0);
	if (has_flag(format->flags, LEFT_JUSTIFY))
		ret_val = left_case(format, str, new_str);
	else
		ret_val = right_case(format, str, new_str);
	return (ret_val);
}
