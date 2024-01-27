/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:17:17 by lluque            #+#    #+#             */
/*   Updated: 2023/11/11 10:08:57 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_conv_less_sig_digl(unsigned long *nbr, int base, char *sym_table)
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

static int	ft_sz_str_decl(unsigned long dec_nbr, int base_for_string)
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

char	*ft_ultoa_b(unsigned long n, unsigned int base, int in_caps)
{
	char	*ret_val;
	int		size;
	int		i;
	char	sym_table[16];

	size = ft_sz_str_decl(n, base);
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	i = size - 2;
	ft_get_sym_table(sym_table, base, in_caps);
	while (i >= 0)
	{
		ret_val[i] = ft_conv_less_sig_digl(&n, base, sym_table);
		i--;
	}
	ret_val[size - 1] = '\0';
	return (ret_val);
}
