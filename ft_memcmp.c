/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:49:21 by lluque            #+#    #+#             */
/*   Updated: 2023/09/26 22:18:11 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	int	return_value;

	i = 0;
	while (i < (signed)n)
	{
		return_value = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (return_value != 0)
			return (return_value);
		i++;
	}
	return (0);
}
