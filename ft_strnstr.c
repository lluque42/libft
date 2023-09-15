/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:57:05 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 03:22:57 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;
	char	*return_value;

	i = 0;
	len_needle = ft_strlen(needle);
	while (i < len && haystack[i] != '\0')
	{
		return_value = (char *)haystack + i;
		if (ft_strncmp(return_value, needle, len_needle) == 0)
			return (return_value);
		i++;
	}
	return (NULL);
}
