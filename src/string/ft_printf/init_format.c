/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:05 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:50:52 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_printf_init_format(t_format *format)
{
	format->flags = NO_FLAGS;
	format->width = 0;
	format->precision = 0;
	format->prec_value = 0;
	format->data_type = NO_TYPE;
	ft_bzero(&(format->data), sizeof (t_data));
	format->literal_char = '\0';
	format->printer_function = NULL;
	format->parser_function = NULL;
}
