/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2024/07/21 00:07:03 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_valid_digit(unsigned char c, unsigned int base)
{
	if (ft_isdigit(c))
		if ((unsigned)(c - '0') < base)
			return (1);
	if (!ft_isdigit(c) && base <= 16)
	{
		if (ft_isupper(c))
		{
			if ((unsigned)(c - 'A' + 10) < base)
				return (1);
		}
		if ((unsigned)(c - 'a' + 10) < base)
			return (1);
	}
	return (0);
}

static int	ft_get_digits_count(const char *str, unsigned int base)
{
	int		digs;

	digs = 0;
	while (is_valid_digit(str[digs], base))
		digs++;
	return (digs);
}

void	update_retval(long *ret_val, int dig_value, int base, int pos)
{
	int	increment;

	increment = dig_value * ft_pow(base, pos);
	*ret_val = *ret_val + increment;
	if (*ret_val > INT_MAX)
		*ret_val = -1;
}

int	ft_atoi_b(const char *str, int base)
{
	int		dc;
	int		k;
	long	ret_val;

	while (ft_isspace(*str))
		str++;
	dc = ft_get_digits_count(str, base);
	if (base < 2 || base > 16 || dc == 0)
		return (-1);
	k = 0;
	ret_val = 0;
	while (k < dc)
	{
		if (ft_isdigit(str[k]))
			ret_val += (str[k] - '0') * ft_pow(base, dc - k - 1);
		if (!ft_isdigit(str[k]) && ft_isupper(str[k]))
			ret_val += (str[k] - 'A' + 10) * ft_pow(base, dc - k - 1);
		if (!ft_isdigit(str[k]) && ft_islower(str[k]))
			ret_val += (str[k] - 'a' + 10) * ft_pow(base, dc - k - 1);
		if ((unsigned)ret_val > INT_MAX)
			return (-1);
		k++;
	}
	return (ret_val);
}
