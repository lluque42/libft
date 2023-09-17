/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:43:09 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 16:10:15 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>								/////////////////////////////////////BORRAR
#include <stdlib.h>
#include "libft.h"

int	ft_size_str_for_dec(int dec_nbr, int base_for_string, int include_sign)
{
	int	size;

	//printf("Entro en ft_size_str_for_dec() con dec_nbr = %d, base_for_string = %d y include_sign = %d\n", dec_nbr, base_for_string, include_sign);
	size = 2;
	if (dec_nbr < 0 && include_sign)
		size++;
	dec_nbr /= base_for_string;
	while (dec_nbr != 0)
	{
		dec_nbr /= base_for_string;
		size++;
	}
	return (size);
}

char	ft_conv_less_sig_dig(int *nbr, int base, char *sym_table)
{
	int		digit;
	char	ret_val;

	digit = *nbr % base;
	if (digit < 0)
		digit *= -1;
	*nbr /= base;
	ret_val = sym_table[digit];
	return (ret_val);
}

char	*ft_get_sym_table_base_10(void)
{
	char	*sym_table_base_10;
	int		i;

	sym_table_base_10 = malloc(10 * sizeof (char));
	i = 0;
	while (i < 10)
	{
		sym_table_base_10[i] = i + '0';
		i++;
	}
	return (sym_table_base_10);
}

char	*ft_itoa(int n)
{
	char	*ret_val;
	int		size;
	int		i;
	int		is_negative;
	char	*sym_table_base_10;

	size = ft_size_str_for_dec(n, 10, 1);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = size - 2;
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	sym_table_base_10 = ft_get_sym_table_base_10();
	while ((!is_negative && i >= 0) || (is_negative && i > 0))
	{
		ret_val[i] = ft_conv_less_sig_dig(&n, 10, sym_table_base_10);
		i--;
	}
	if (is_negative)
		ret_val[0] = '-';
	ret_val[size - 1] = '\0';
	free(sym_table_base_10);
	return (ret_val);
}
