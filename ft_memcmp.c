/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:49:21 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 03:25:03 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		return_value;

	i = 0;
	if (n == 0)
		return (0);
	return_value = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	while (return_value == 0 && i < n)
	{
		i++;
		return_value = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	}
	return (return_value);
}
