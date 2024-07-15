/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:21 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 01:27:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_get_sym_table(char *sym_table, unsigned int base, int in_caps)
{
	unsigned int	i;
	char			a;

	if (base > 16 || base == 0)
		return (NULL);
	if (in_caps)
		a = 'A';
	else
		a = 'a';
	i = 0;
	while (i < 16)
	{
		if (i < 10)
			sym_table[i] = i + '0';
		else
			sym_table[i] = i - 10 + a;
		i++;
	}
	return (sym_table);
}

/*
NAME
	ft_size_str_for_dec -- Obtain a size for a string in which a int fits

DESCRIPTION
	...

PARAMETERS


RETURN VALUES
	The size of the string, including memory for '\0' and optionally for
	negative sign

******PROBLEMS*******

*/
static int	ft_size_str_for_dec(unsigned int dec_nbr, int base_for_string)
{
	int	size;

	size = 2;
	dec_nbr /= base_for_string;
	while (dec_nbr != 0)
	{
		dec_nbr /= base_for_string;
		size++;
	}
	return (size);
}

/*
NAME
	ft_conv_less_sig_dig -- Converts less significative digit to a char

DESCRIPTION
	Takes a pointer to an integer...

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
static char	ft_conv_less_sig_dig(unsigned int *nbr, int base, char *sym_table)
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

char	*ft_uitoa_b(unsigned int n, unsigned int base, int in_caps)
{
	char	*ret_val;
	int		size;
	int		i;
	char	sym_table[16];

	if (ft_get_sym_table(sym_table, base, in_caps) == NULL)
		return (NULL);
	size = ft_size_str_for_dec(n, base);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = size - 2;
	while (i >= 0)
	{
		ret_val[i] = ft_conv_less_sig_dig(&n, base, sym_table);
		i--;
	}
	ret_val[size - 1] = '\0';
	return (ret_val);
}
