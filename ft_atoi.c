/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:42:26 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 20:10:24 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN_SPACES 0
#define IN_SIGN 0
#define IN_DIGITS 0

/*
NAME
	ft_isspace -- White-space character test

DESCRIPTION
	The isspace() function tests for the white-space characters.
	For any locale, this includes the following standard characters:
		'\t'	'\n'	'\v'	'\f'	'\r'	' '

PARAMETERS


RETURN VALUES
	The isspace() function returns zero if the character tests false and
	returns non-zero if the character tests true.

******PROBLEMS*******

*/
static int	ft_isspace(int c)
{
	if (c != '\t' && c != '\n' && c != '\v')
	{
		if (c != '\f' && c != '\r' && c != ' ')
			return (0);
	}
	return (1);
}

/*
NAME
	ft_issign -- Test for sign char

DESCRIPTION
	Checks character passed as argument looking for a sign char or its abscence

PARAMETERS


RETURN VALUES
	Returns -1 if c is '-'; +1 if c is '+'; 0 if c is neither '+' or '-'
	
******PROBLEMS*******

*/
static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

/*
NAME
	ft_pow -- Power function

DESCRIPTION
	The pow() functions compute base raised to the power exp.

PARAMETERS


RETURN VALUES
	base^exp
	
******PROBLEMS*******

*/
static int	ft_pow(int base, int exp)
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
