/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:39:26 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:52:37 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"
#define IN_FLAGS 0
#define IN_WIDTH 1
#define IN_PRECISION 2
#define IN_PREC_VAL 3
#define IN_SPECIFIER 4

int	parse_flags(t_format *format, char **str)
{
	while (ft_strchr(SUPP_FLAGS, **str) != NULL)
	{
		if (**str == '-')
			set_flag(&(format->flags), LEFT_JUSTIFY);
		if (**str == ' ')
			set_flag(&(format->flags), BLANK_IF_POS_NUM);
		if (**str == '+')
			set_flag(&(format->flags), SIGN_BEF_NUM);
		if (**str == '0')
			set_flag(&(format->flags), ZERO_PADDING);
		if (**str == '#')
			set_flag(&(format->flags), ALTERNATE_FORM);
		(*str)++;
	}
	return (1);
}

int	parse_width(t_format *format, char **str)
{
	int		width;

	if (ft_isdigit(**str))
	{
		width = ft_atoi(*str);
		format->width = width;
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (1);
}

int	parse_precision(t_format *format, char **str)
{
	int		prec_value;

	prec_value = 0;
	if (**str == '.')
	{
		format->precision = 1;
		(*str)++;
		if (ft_isdigit(**str))
		{
			prec_value = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
	format->prec_value = prec_value;
	return (1);
}

int	parse_format(t_format *format, char **str)
{
	if (!parse_flags(format, str))
		return (0);
	if (!parse_width(format, str))
		return (0);
	if (!parse_precision(format, str))
		return (0);
	return (1);
}
