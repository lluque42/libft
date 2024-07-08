/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:07:08 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:38:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_parser_select(t_format *format, char **str)
{
	if (**str == '%')
	{
		(*str)++;
		if (!ft_printf_parse_format(format, str))
			return (0);
		format->parser_function = ft_printf_parse_conversion;
	}
	else
		format->parser_function = ft_printf_parse_literal_char;
	return (1);
}
