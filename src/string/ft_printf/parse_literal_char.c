/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_literal_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:41:59 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:50:04 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf_parse_literal_char(t_format *format, char **str)
{
	format->data_type = LITERAL_CHAR;
	format->literal_char = **str;
	(*str)++;
	return (1);
}
