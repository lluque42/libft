/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:43:05 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 02:48:15 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*return_value;

	i = 0;
	return_value = (char *)s;
	while (i < n)
	{
		if (*return_value == (unsigned char)c)
			return (return_value);
		return_value++;
		i++;
	}
	return (NULL);
}
