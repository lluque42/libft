/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:43:06 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:25:33 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_utils.h"
#define NUL_CHAR_REPLACEMENT 64

static int	literal_char_case(t_format *format, char **str)
{
	int	printed_chars;

	printed_chars = 0;
	if (format->data_type == ESCAPED_PERCENT)
	{
		**str = '%';
		if (!ft_printf_add_width_alignment(format, str))
		{
			free(str);
			return (-1);
		}
	}
	if (format->data_type == LITERAL_CHAR)
		**str = format->literal_char;
	printed_chars = ft_putstr_fd_safe(*str, 1);
	if ((signed)ft_strlen(*str) != printed_chars)
	{
		free(*str);
		return (-1);
	}
	return (printed_chars);
}

static int	nul_char_case(t_format *format, char **str)
{
	int	i;
	int	printed_chars;

	printed_chars = 0;
	**str = (char)NUL_CHAR_REPLACEMENT;
	if (!ft_printf_add_width_alignment(format, str))
	{
		free(str);
		return (-1);
	}
	i = 0;
	while (*(*str + i) != '\0')
	{
		if (*(*str + i) == NUL_CHAR_REPLACEMENT)
			printed_chars += ft_putchar_fd_safe('\0', 1);
		else
			printed_chars += ft_putchar_fd_safe(*(*str + i), 1);
		i++;
	}
	if ((signed)ft_strlen(*str) != printed_chars)
	{
		free(*str);
		return (-1);
	}
	return (printed_chars);
}

static int	char_case(t_format *format, char **str, va_list *arg_list)
{
	int	printed_chars;

	printed_chars = 0;
	format->data.int_type = va_arg(*arg_list, int);
	**str = format->data.int_type;
	if (format->data.int_type == 0)
		return (nul_char_case(format, str));
	if (!ft_printf_add_width_alignment(format, str))
	{
		free(*str);
		return (-1);
	}
	printed_chars = ft_putstr_fd_safe(*str, 1);
	if ((signed)ft_strlen(*str) != printed_chars)
	{
		free(*str);
		return (-1);
	}
	return (printed_chars);
}

// char is promoted to int when passing through ...
int	ft_printf_print_char(t_format *frmt, va_list *arg_list)
{
	char	*str;
	int		printed_chars;

	str = ft_strdup(" ");
	if (str == NULL)
		return (0);
	if (frmt->data_type == LITERAL_CHAR || frmt->data_type == ESCAPED_PERCENT)
		printed_chars = literal_char_case(frmt, &str);
	if (frmt->data_type == CHAR)
		printed_chars = char_case(frmt, &str, arg_list);
	if (printed_chars == -1)
		return (0);
	frmt->printed_chars += printed_chars;
	free(str);
	return (1);
}
