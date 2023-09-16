/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:26:31 by lluque            #+#    #+#             */
/*   Updated: 2023/09/16 14:39:51 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If destination overlaps source, it is possible that at some point the
// original data in source gets corrupted before it's been copied into dst.
// Problematic case: 	If reading src from the beginning
// 						dst > src && src + len > dst
// 	0123456789012345678901234567
// 	ssssssssssssssssssssssss	
// 		dddddddddddddddddddddddd
// 	
// To avoid this, src must be read from the end 
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst > src && src + len > dst)
	{
		i = len - 1;
		while (i >= 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
