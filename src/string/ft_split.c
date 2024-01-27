/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:43:37 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 18:44:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
NAME
	--

DESCRIPTION



PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
static int	ft_word_count(const char *s, char delimiter)
{
	int		i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (!in_word && s[i] != delimiter)
		{
			count++;
			in_word = 1;
		}
		else if (in_word && s[i] == delimiter)
			in_word = 0;
		i++;
	}
	return (count);
}

/*
NAME
	--

DESCRIPTION



PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
static char	*ft_get_next_word(const char **s, char delimiter)
{
	int		start;
	int		size;
	char	*ret_val;

	start = 0;
	while (*(*s + start) != '\0')
	{
		if (*(*s + start) != delimiter)
			break ;
		start++;
	}
	size = 1;
	while (*(*s + start + size) != '\0')
	{
		if (*(*s + start + size) == delimiter)
			break ;
		size++;
	}
	ret_val = ft_substr(*s, start, size);
	if (ret_val == NULL)
		return (NULL);
	*s = *s + start + size;
	return (ret_val);
}

/*
NAME
	ft_free_str_array -- Frees allocated memory for array of strings

DESCRIPTION
	Takes a pointer to a pointer of char (array of strings) and the amount
	of elements of the array with memory allocated. This function frees the
	number of elements indicated (starting at element 0) and finally also
	frees the **char

PARAMETERS


RETURN VALUES
	None

******PROBLEMS*******

*/
static void	ft_free_str_array(char **str_array, int allocated_strings)
{
	int	i;

	i = 0;
	while (i <= allocated_strings)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_val;
	int		strings;
	int		i_string;
	char	*string;

	strings = ft_word_count(s, c);
	ret_val = malloc((strings + 1) * sizeof (char **));
	if (ret_val == NULL)
		return (NULL);
	ret_val[strings] = NULL;
	i_string = 0;
	while (i_string < strings)
	{
		string = ft_get_next_word(&s, c);
		if (string == NULL)
		{
			ft_free_str_array(ret_val, i_string - 1);
			return (NULL);
		}
		ret_val[i_string] = string;
		i_string++;
	}
	return (ret_val);
}
