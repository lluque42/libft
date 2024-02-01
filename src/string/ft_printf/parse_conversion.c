/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:40:31 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:51:50 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#define IN_FLAGS 0
#define IN_WIDTH 1
#define IN_PRECISION 2
#define IN_PREC_VAL 3
#define IN_SPECIFIER 4

int	parse_conversion(t_format *format, char **str)
{
	if (ft_strchr(SUPP_CONV_SPEC, **str) == NULL)
		return (0);
	if (**str == 'c')
		format->data_type = CHAR;
	if (**str == 's')
		format->data_type = STRING;
	if (**str == 'p')
		format->data_type = POINTER;
	if (**str == 'd')
		format->data_type = DECIMAL;
	if (**str == 'i')
		format->data_type = INT;
	if (**str == 'u')
		format->data_type = UINT;
	if (**str == 'x')
		format->data_type = HEX_LOWER;
	if (**str == 'X')
		format->data_type = HEX_UPPER;
	if (**str == '%')
		format->data_type = ESCAPED_PERCENT;
	(*str)++;
	return (1);
}
