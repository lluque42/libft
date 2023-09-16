/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:43:09 by lluque            #+#    #+#             */
/*   Updated: 2023/09/16 13:18:44 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_size_str_for_dec(int dec_nbr, int base_for_string)
{
	int	size;

	size = 1;
	while (dec_nbr / base_for_string != 0)
		size++;
	if (dec_nbr < 0)
		size++;
	return (size);
}

char	ft_extract_less_sig_symbol(int *nbr, int base, char *sym_table)
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
	char	*sym_table_base_10;

	size = ft_size_str_for_dec(n, 10);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ret_val[0] = '-';
		i++;
	}
	sym_table_base_10 = ft_get_sym_table_base_10();
	while (i < size - 1)
	{
		ret_val[i] = ft_extract_less_sig_symbol(&n, 10, sym_table_base_10);
	}
	ret_val[size - 1] = '\0';
	free(sym_table_base_10);
	return (ret_val);
}
