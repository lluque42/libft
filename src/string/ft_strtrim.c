/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:37:23 by lluque            #+#    #+#             */
/*   Updated: 2023/09/26 20:14:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ret_val;
	int		size;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end)
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	while (end > start)
	{
		if (ft_strchr(set, s1[end]) == NULL)
			break ;
		end--;
	}
	size = end - start + 2;
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_strlcpy(ret_val, s1 + start, size);
	return (ret_val);
}
