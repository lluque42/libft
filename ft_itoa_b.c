/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:21 by lluque            #+#    #+#             */
/*   Updated: 2023/11/03 16:37:44 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
static int	ft_size_str_for_dec(int dec_nbr, int base_for_string, int inc_sign)
{
	int	size;

	size = 2;
	if (dec_nbr < 0 && inc_sign)
		size++;
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
static char	ft_conv_less_sig_dig(int *nbr, int base, char *sym_table)
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

/*
NAME
	ft_get_sym_table --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
static void	ft_get_sym_table(char *sym_table, int in_caps)
{
	unsigned int	i;
	char			a;

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
}

char	*ft_itoa_b(int n, unsigned int base, int in_caps)
{
	char	*ret_val;
	int		size;
	int		i;
	int		is_negative;
	char	sym_table[16];

	ft_get_sym_table(sym_table, in_caps);
	size = ft_size_str_for_dec(n, base, 1);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = size - 2;
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	while ((!is_negative && i >= 0) || (is_negative && i > 0))
	{
		ret_val[i] = ft_conv_less_sig_dig(&n, base, sym_table);
		i--;
	}
	if (is_negative)
		ret_val[0] = '-';
	ret_val[size - 1] = '\0';
	return (ret_val);
}
