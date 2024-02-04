/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aisi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:20:45 by lluque            #+#    #+#             */
/*   Updated: 2024/02/04 16:07:41 by lluque           ###   ########.fr       */
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
// At this point neither str or the limits have signs chars
// Sentence if same length
// At this point both have same length and further examination is required
static int	in_int_range(const char *str)
{
	int		is_neg;
	char	*s_max;
	char	*s_min;
	int		is_valid;
	int		i;

	is_valid = 1;
	s_max = ft_itoa(INT_MAX);
	s_min = ft_itoa(INT_MIN) + 1;
	is_neg = get_clean_pos_number(&str);
	if (ft_strlen(s_max) != ft_strlen(str))
		is_valid = ft_strlen(str) < ft_strlen(s_max);
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			if ((is_neg && str[i] > s_min[i]) || (!is_neg && str[i] > s_max[i]))
				is_valid = 0;
			i++;
		}
	}
	return (free(s_max), free(s_min - 1), is_valid);
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
