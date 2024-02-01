/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:41:52 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:53:59 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

static int	add_precision_for_strings(t_format *format, char **str)
{
	size_t	str_len;

	if (!format->precision)
		return (1);
	str_len = ft_strlen(*str);
	if (format->prec_value >= str_len)
		return (1);
	*(*str + format->prec_value) = '\0';
	return (1);
}

int	print_string(t_format *format, va_list *arg_list)
{
	size_t	printed_chars;
	char	*str;

	str = NULL;
	format->data.string_type = va_arg(*arg_list, char *);
	if (format->data.string_type != NULL)
		str = ft_strdup(format->data.string_type);
	else
		str = ft_strdup("(null)");
	if (str == NULL)
		return (0);
	if (!add_precision_for_strings(format, &str))
		return (free_and_return_value(str, 0));
	if (!add_width_alignment(format, &str))
		return (free_and_return_value(str, 0));
	printed_chars = ft_putstr_fd_safe(str, 1);
	if (printed_chars != ft_strlen(str))
		return (free_and_return_value(str, 0));
	free(str);
	format->printed_chars += printed_chars;
	return (1);
}
