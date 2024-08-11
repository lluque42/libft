/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aisi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:20:45 by lluque            #+#    #+#             */
/*   Updated: 2024/08/11 16:07:59 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"

static int	get_clean_pos_number(const char **str)
{
	int		is_neg;

	is_neg = 0;
	if ((*str)[0] == '-')
		is_neg = 1;
	if (ft_issign((*str)[0]))
		(*str)++;
	while (**str == '0')
		(*str)++;
	return (is_neg);
}

// Takes a valid str representation of a number (could begin with + or - sign)
// and returns non-zero if the number is within int range according to C's 
// limits.h. header.  
// Strings "+0" and "-0" are valid and equivalent to "0".
// The possible sign is removed from str string to allow str_comparing against
// the string representations of INT_MAX and INT_MIN (also without signs). A
// variable preserves the sign info to later choose what to compare against.
// The value represented in str string is neccesary within range when:
// 	* Then len of the string representations of INT_MAX (or INT_MIN) is greater
// 	than the len of str string.
// 	* The str string is exactly the same as either the INT_MAX or INT_MIN
// 	string representations.
// If it is still not conclusive, then a char-by-char comparison is performed
// against the right limit (the storaged sign info determines which limit to
// compare with). The char-by-char comparison starts at the most significant
// character and may continue until '\0'. Since it was already concluded that
// str is NOT equal to either the INT_MAX or INT_MIN string representations,
// if any of the limit character is greater than the respective str string
// character, a 1 is returned inmediately (i.e. the value in str is within
// range). If the former never happens and the char-by-char comparison reaches
// '\0', ending the char-by-char comparison loop, it could only mean that
// str value is NOT inside the range.
static int	in_int_range(const char *str)
{
	int		is_neg;
	char	*s_max;
	char	*s_min;
	int		i;

	s_max = ft_itoa(INT_MAX);
	s_min = ft_itoa(INT_MIN) + 1;
	is_neg = get_clean_pos_number(&str);
	if (ft_strlen(str) < ft_strlen(s_max))
		return (free(s_max), free(s_min - 1), 1);
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			if ((is_neg && s_min[i] > str[i])
				|| (!is_neg && s_max[i] > str[i]))
				return (free(s_max), free(s_min - 1), 1);
			i++;
		}
	}
	if ((!is_neg && ft_strncmp(str, s_max, ft_strlen(s_max) + 1) == 0)
		|| (is_neg && ft_strncmp(str, s_min, ft_strlen(s_min) + 1) == 0))
		return (free(s_max), free(s_min - 1), 1);
	return (free(s_max), free(s_min - 1), 0);
}

int	ft_aisi(const char *str)
{
	unsigned int	i;

	if ((!ft_isdigit(str[0]) && !ft_issign(str[0])) || str[0] == '\0')
		return (0);
	if (ft_issign(str[0]))
		i = 1;
	else
		i = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (in_int_range(str));
}
