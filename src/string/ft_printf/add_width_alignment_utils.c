/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_alignment_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:45:53 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:46:17 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

// For right-justify alignment and zero padding of conversions which support it
void	ft_printf_leading_ack(t_format *format, int *original_sign, int *prefix)
{
	if (format->data_type == INT || format->data_type == DECIMAL)
		*original_sign = 1;
	else
		*original_sign = 0;
	*prefix = 0;
	if (format->data_type == HEX_LOWER || format->data_type == HEX_UPPER)
		*prefix = 1;
	if (format->data_type == POINTER)
		*prefix = 1;
}

// For right-justify zero padding of conversions which support it
int	ft_printf_right_zero_case(t_format *format, char **str, char *new_str)
{
	int		original_sign_matters;
	int		prefix_matters;
	int		offset;
	int		zeros;
	int		str_len;

	offset = 0;
	ft_printf_leading_ack(format, &original_sign_matters, &prefix_matters);
	if (original_sign_matters && ft_strchr("+- ", **str) != NULL)
		offset = 1;
	if (prefix_matters && !ft_strncmp(*str, "0x", 2))
		offset = 2;
	if (prefix_matters && !ft_strncmp(*str, "0X", 2))
		offset = 2;
	str_len = ft_strlen(*str);
	zeros = format->width - str_len;
	if (zeros <= 0)
		return (1);
	ft_memcpy(new_str, *str, offset);
	ft_memset(new_str + offset, '0', zeros);
	new_str[offset + zeros] = '\0';
	ft_strlcpy(new_str + offset + zeros, *str + offset, format->width + 1);
	free(*str);
	*str = new_str;
	return (1);
}

// For right-justify space padding
int	ft_printf_right_space_case(t_format *format, char **str, char *new_str)
{
	int	str_len;
	int	spaces;

	str_len = ft_strlen(*str);
	spaces = format->width - str_len;
	if (spaces <= 0)
		return (1);
	ft_memset(new_str, ' ', spaces);
	new_str[spaces] = '\0';
	ft_strlcat(new_str, *str, format->width + 1);
	free(*str);
	*str = new_str;
	return (1);
}

/*
When compiling for Linux (Ubuntu distro) the following conversions
are NOT compatible with right alignment zero padding:
	%c
	%s
Also, for Linux the NULL pointer in %p conversions is NOT a compatible
type for right-justify zero padding.
Differences:
// ONLY for Linux binary
//	if (format->data_type == POINTER && format->data.ptr_type != NULL)
// NEW for MacOS binary
	if (format->data_type == POINTER)
		zero_pad_compatible_conversion++;
// NEW for MacOS binary
	if (format->data_type == CHAR || format->data_type == STRING)
		zero_pad_compatible_conversion++;
*/
// For right-justify
//	zero_pad_compatible_conversion = 0;
int	ft_printf_right_case(t_format *format, char **str, char *new_str)
{
	int	ret_val;
	int	zero_pad_comp_conv;

	zero_pad_comp_conv = 0;
	if (format->data_type == INT && !format->precision)
		zero_pad_comp_conv++;
	if (format->data_type == UINT && !format->precision)
		zero_pad_comp_conv++;
	if (format->data_type == DECIMAL && !format->precision)
		zero_pad_comp_conv++;
	if (format->data_type == HEX_LOWER && !format->precision)
		zero_pad_comp_conv++;
	if (format->data_type == HEX_UPPER && !format->precision)
		zero_pad_comp_conv++;
	if (format->data_type == POINTER)
		zero_pad_comp_conv++;
	if (format->data_type == CHAR || format->data_type == STRING)
		zero_pad_comp_conv++;
	if (ft_printf_has_flag(format->flags, ZERO_PADDING) && zero_pad_comp_conv)
	{
		ret_val = ft_printf_right_zero_case(format, str, new_str);
		return (ret_val);
	}
	ret_val = ft_printf_right_space_case(format, str, new_str);
	return (ret_val);
}

// For left-justify, only applies space-padding.
int	ft_printf_left_case(t_format *format, char **str, char *new_str)
{
	int	str_len;
	int	spaces;

	str_len = ft_strlen(*str);
	spaces = format->width - str_len;
	if (spaces <= 0)
		return (1);
	ft_memcpy(new_str, *str, str_len);
	ft_memset(new_str + str_len, ' ', spaces);
	new_str[format->width] = '\0';
	free(*str);
	*str = new_str;
	return (1);
}
