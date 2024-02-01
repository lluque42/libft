/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:43:27 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:52:05 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

static int	add_sign_flag(t_format *format, char **nbr)
{
	char	*new_nbr;
	int		new_nbr_size;

	if (format->data_type != INT && format->data_type != DECIMAL)
		return (1);
	if (has_flag(format->flags, BLANK_IF_POS_NUM | SIGN_BEF_NUM))
	{
		new_nbr_size = ft_strlen(*nbr) + 1 + 1;
		new_nbr = malloc(new_nbr_size * sizeof (char));
		if (new_nbr == NULL)
			return (0);
		ft_bzero(new_nbr, new_nbr_size);
		if (has_flag(format->flags, SIGN_BEF_NUM))
			ft_strlcat(new_nbr, "+", new_nbr_size);
		if (has_flag(format->flags, BLANK_IF_POS_NUM))
			ft_strlcat(new_nbr, " ", new_nbr_size);
		ft_strlcat(new_nbr, *nbr, new_nbr_size);
		free(*nbr);
		*nbr = new_nbr;
	}
	return (1);
}

int	print_integer(t_format *format, va_list *arg_list)
{
	size_t	printed_chars;
	char	*nbr;

	format->data.int_type = va_arg(*arg_list, int);
	if (format->data_type == UINT)
		nbr = ft_ltoa(format->data.long_type);
	if (format->data_type == INT || format->data_type == DECIMAL)
		nbr = ft_itoa(format->data.int_type);
	if (nbr == NULL)
		return (0);
	if (format->data.int_type >= 0 && !add_sign_flag(format, &nbr))
		return (free_and_return_value(nbr, 0));
	if (!add_precision_for_numbers(format, &nbr))
		return (free_and_return_value(nbr, 0));
	if (!add_width_alignment(format, &nbr))
		return (free_and_return_value(nbr, 0));
	printed_chars = ft_putstr_fd_safe(nbr, 1);
	if (ft_strlen(nbr) != printed_chars)
		return (free_and_return_value(nbr, 0));
	free(nbr);
	format->printed_chars += printed_chars;
	return (1);
}
