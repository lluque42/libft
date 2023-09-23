/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:43:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/23 13:26:09 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strcount(char const *s, char c)
{
	char	*index;
	int		ret_val;

	ret_val = 0;
	index = (char *)s;
	while (index != NULL)
	{
		index = ft_strchr(index, c);
		if (index != NULL)
		{
			index++;
			ret_val++;
		}
	}
	return (ret_val);
}

char	*ft_strextract(char *s,	size_t pos)
{
	char	*ret_val;
	int		i;

	ret_val = ft_strdup(s + pos);
	if (ret_val == NULL)
		return (NULL);
	i = pos;
	while (s[i] != '\0')
		s[i] = '\0';
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
	int		new_strings;
	int		i;
	int		delimiter_pos;

	new_strings = ft_strcount(s, c) + 1;
	ret_val = malloc((new_strings + 1) * sizeof (char **));
	if (ret_val == NULL)
		return (NULL);
	ret_val[new_strings] = NULL;
	i = 0;
	while (i < new_strings)
	{
		delimiter_pos = ft_strchr(s, c) - s;
		ret_val[i] = ft_substr(s, 0, delimiter_pos);
		if (ret_val == NULL)
		{
			ft_free_str_array(ret_val, i - 1);
			break ;
		}
		s = s + delimiter_pos + 1;
		i++;
	}
	return (ret_val);
}
