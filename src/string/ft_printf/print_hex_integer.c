/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:15:08 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:51:04 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

static int	add_alternate_form_flag(t_format *format, char **nbr)
{
	char	*new_nbr;
	int		new_nbr_size;

	if (has_flag(format->flags, ALTERNATE_FORM))
	{
		if (format->data.long_type != 0)
			new_nbr_size = ft_strlen(*nbr) + 2 + 1;
		else
			return (1);
		new_nbr = malloc(new_nbr_size * sizeof (char));
		if (new_nbr == NULL)
			return (0);
		ft_bzero(new_nbr, new_nbr_size);
		if (format->data_type == HEX_UPPER && format->data.long_type != 0)
			ft_strlcat(new_nbr, "0X", new_nbr_size);
		if (format->data_type == HEX_LOWER && format->data.long_type != 0)
			ft_strlcat(new_nbr, "0x", new_nbr_size);
		ft_strlcat(new_nbr, *nbr, new_nbr_size);
		free(*nbr);
		*nbr = new_nbr;
	}
	return (1);
}

int	print_hex_integer(t_format *format, va_list *arg_list)
{
	size_t	printed_chars;
	long	u_integer;
	char	*nbr;

	format->data.int_type = va_arg(*arg_list, int);
	u_integer = format->data.long_type;
	if (format->data_type == HEX_UPPER)
		nbr = ft_ltoa_b(u_integer, 16, 1);
	if (format->data_type == HEX_LOWER)
		nbr = ft_ltoa_b(u_integer, 16, 0);
	if (nbr == NULL)
		return (0);
	if (!add_precision_for_numbers(format, &nbr))
		return (free_and_return_value(nbr, 0));
	if (!add_alternate_form_flag(format, &nbr))
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
