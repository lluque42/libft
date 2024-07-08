/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_for_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:01:19 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 01:30:41 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

// When precision is demanded and both precision and variable value are 0
static int	special_case(char **nbr, int original_sign_matters)
{
	char	*new_nbr;

	if (!ft_isdigit(**nbr) && original_sign_matters)
	{
		new_nbr = malloc(2 * sizeof (char));
		if (new_nbr == NULL)
			return (0);
		*new_nbr = **nbr;
		*(new_nbr + 1) = '\0';
	}
	else
	{
		new_nbr = malloc(sizeof (char));
		if (new_nbr == NULL)
			return (0);
		*new_nbr = '\0';
	}
	free(*nbr);
	*nbr = new_nbr;
	return (1);
}

static int	general_case(t_format *format, char **nbr, int sign_matters)
{
	char	*new_nbr;
	int		zeros;
	int		new_nbr_len;
	int		i;

	zeros = format->prec_value - ft_strlen(*nbr);
	if (!ft_isdigit(**nbr) && sign_matters)
		zeros++;
	if (zeros <= 0)
		return (1);
	new_nbr_len = ft_strlen(*nbr) + zeros;
	new_nbr = malloc((new_nbr_len + 1) * sizeof (char));
	if (new_nbr == NULL)
		return (0);
	i = !ft_isdigit(**nbr) * sign_matters;
	if (i)
		new_nbr[0] = **nbr;
	ft_memset(new_nbr + i, '0', zeros);
	new_nbr[i + zeros] = '\0';
	ft_strlcpy(new_nbr + i + zeros, *nbr + i, new_nbr_len + 1 - i - zeros);
	free(*nbr);
	*nbr = new_nbr;
	return (1);
}

int	ft_printf_add_precision_for_numbers(t_format *format, char **nbr)
{
	int		original_sign_matters;

	if (!format->precision)
		return (1);
	original_sign_matters = 0;
	if (format->data_type == INT || format->data_type == DECIMAL)
		original_sign_matters = 1;
	if (format->prec_value == 0 && format->data.int_type == 0)
		return (special_case(nbr, original_sign_matters));
	return (general_case(format, nbr, original_sign_matters));
}
