/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:39 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:28:26 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg_list;
	t_format	format;
	char		*string;

	string = (char *)str;
	va_start(arg_list, str);
	format.printed_chars = 0;
	while (*string != '\0')
	{
		ft_printf_init_format(&format);
		if (!ft_printf_parser_select(&format, &string))
			return (-1);
		if (!format.parser_function(&format, &string))
			return (-1);
		if (!ft_printf_printer_select(&format))
			return (-1);
		if (!format.printer_function(&format, &arg_list))
			return (-1);
	}
	va_end(arg_list);
	return (format.printed_chars);
}
