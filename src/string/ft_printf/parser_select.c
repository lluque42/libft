/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:07:08 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:54:16 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	parser_select(t_format *format, char **str)
{
	if (**str == '%')
	{
		(*str)++;
		if (!parse_format(format, str))
			return (0);
		format->parser_function = parse_conversion;
	}
	else
		format->parser_function = parse_literal_char;
	return (1);
}
