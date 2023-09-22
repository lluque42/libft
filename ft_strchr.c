/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:48:50 by lluque            #+#    #+#             */
/*   Updated: 2023/09/21 18:54:46 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*return_value;

	i = 0;
	return_value = (char *)s;
	len = ft_strlen(s);
	if (c == '\0')
		return (return_value + len);
	while (i < len)
	{
		if (*return_value == (char)c)
			return (return_value);
		return_value++;
		i++;
	}
	return (NULL);
}
