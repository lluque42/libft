/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2023/09/14 13:59:33 by lluque           ###   ########.fr       */
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
	}
	return (ret_val);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		len;
	int		i;
	long	ret_val;
	char	buffer[11];

	i = 0;
	len = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		sign = ft_issign(str[i]);
		if (sign == 0)
			return (0);
	}
	while (ft_isdigit(str[i]))
		len++;
	while (i < len)
	{
		ret_val = ret_val + (buffer[i] - '\0') * ft_exp(10, len - 1 - i);
		i++;
	}
	return (sign * ret_val);
}
