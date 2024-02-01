/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:40:04 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:54:34 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	printer_select(t_format *format)
{
	if (format->data_type == CHAR || format->data_type == LITERAL_CHAR)
		format->printer_function = print_char;
	if (format->data_type == STRING)
		format->printer_function = print_string;
	if (format->data_type == ESCAPED_PERCENT)
		format->printer_function = print_char;
	if (format->data_type == POINTER)
		format->printer_function = print_pointer;
	if (format->data_type == INT || format->data_type == UINT)
		format->printer_function = print_integer;
	if (format->data_type == DECIMAL)
		format->printer_function = print_integer;
	if (format->data_type == HEX_LOWER || format->data_type == HEX_UPPER)
		format->printer_function = print_hex_integer;
	return (1);
}
