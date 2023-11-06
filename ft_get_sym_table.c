/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sym_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:09:55 by lluque            #+#    #+#             */
/*   Updated: 2023/11/03 17:40:39 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_get_sym_table(char *sym_table, unsigned int base, int in_caps)
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
