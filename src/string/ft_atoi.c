/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2023/11/03 15:38:23 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN_SPACES 0
#define IN_SIGN 0
#define IN_DIGITS 0

static int	ft_get_digits(const char *str)
{
	int		digs;

	digs = 0;
	while (ft_isdigit(str[digs]))
		digs++;
	return (digs);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		digs;
	int		offset;
	int		k;
	long	ret_val;

	offset = 0;
	sign = 1;
	while (ft_isspace(str[offset]))
		offset++;
	if (!ft_isdigit(str[offset]))
		sign = ft_issign(str[offset]);
	if (ft_issign(str[offset]) && sign == 0)
		return (0);
	else if (ft_issign(str[offset]))
		offset++;
	digs = ft_get_digits(str + offset);
	k = 0;
	ret_val = 0;
	while (k < digs)
	{
		ret_val = ret_val + (str[k + offset] - '0') * ft_pow(10, digs - k - 1);
		k++;
	}
	return (sign * ret_val);
}
