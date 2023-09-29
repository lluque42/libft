/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:43:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/29 15:20:56 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_word_count(const char *s, char delimiter)
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

char	*ft_get_next_word(const char **s, char delimiter)
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
	*s = *s + start + size;
	return (ret_val);
}

void	ft_free_str_array(char **str_array, int allocated_strings)
{
	int	i;

	i = 0;
	while (i < allocated_strings)
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
	int		string;

	strings = ft_word_count(s, c);
	ret_val = malloc((strings + 1) * sizeof (char **));
	if (ret_val == NULL)
		return (NULL);
	ret_val[strings] = NULL;
	string = 0;
	while (string < strings)
	{
		ret_val[string] = ft_get_next_word(&s, c);
		string++;
	}
	return (ret_val);
}
