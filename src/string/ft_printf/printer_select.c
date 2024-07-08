/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:40:04 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:49:35 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_printer_select(t_format *format)
{
	if (format->data_type == CHAR || format->data_type == LITERAL_CHAR)
		format->printer_function = ft_printf_print_char;
	if (format->data_type == STRING)
		format->printer_function = ft_printf_print_string;
	if (format->data_type == ESCAPED_PERCENT)
		format->printer_function = ft_printf_print_char;
	if (format->data_type == POINTER)
		format->printer_function = ft_printf_print_pointer;
	if (format->data_type == INT || format->data_type == UINT)
		format->printer_function = ft_printf_print_integer;
	if (format->data_type == DECIMAL)
		format->printer_function = ft_printf_print_integer;
	if (format->data_type == HEX_LOWER || format->data_type == HEX_UPPER)
		format->printer_function = ft_printf_print_hex_integer;
	return (1);
}
