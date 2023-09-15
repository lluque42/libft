/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:43:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/15 17:44:11 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strcount(char const *s, char c)
{
	char	*index;
	int		ret_val;

	ret_val = 0;
	index = (char *)s;
	while (index != NULL)
	{
		index = ft_strchr(index, c);
		ret_val++;
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

char	**ft_split(char const *s, char c)
{
	char	*copy;
	char	**ret_val;
	int		new_strings;
	int		i;
	int		delimiter_pos;

	new_strings = ft_strcount(s, c) + 1;
	ret_val = malloc((new_strings + 1) * sizeof (char **));
	if (ret_val == NULL)
		return (NULL);
	ret_val[new_strings] = NULL;
	i = new_strings - 1;
	copy = ft_strdup(s);
	while (i >= 0)
	{
		delimiter_pos = ft_strrchr(copy, c) - copy;
		ret_val[i] = ft_strextract(copy, delimiter_pos + 1);
		copy[delimiter_pos] = '\0';
		if (ret_val == NULL)
		{
			while (i <= new_strings - 1)
				free(ret_val[i]);
			free(ret_val);
			ret_val = NULL;
			break ;
		}
		i--;
	}
	free(copy);
	return (ret_val);
}
