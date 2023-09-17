/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 15:09:39 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN_SPACES 0
#define IN_SIGN 0
#define IN_DIGITS 0

int	ft_isspace(int c)
{
	if (c != '\t' && c != '\n' && c != '\v')
	{
		if (c != '\f' && c != '\r' && c != ' ')
			return (0);
	}
	return (1);
}

// Returns -1 if c is '-'; +1 if c is '+'; 0 if c is neither '+' or '-'
int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int	ft_exp(int base, int exp)
{
	int	ret_val;
	int	i;

	i = 0;
	ret_val = 1;
	while (i < exp)
	{
		ret_val *= base;
		i++;
	}
	return (ret_val);
}

int	ft_get_digits(const char *str)
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
		ret_val = ret_val + (str[k + offset] - '0') * ft_exp(10, digs - k - 1);
		k++;
	}
	return (sign * ret_val);
}
