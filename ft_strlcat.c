/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:03:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/28 21:03:44 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	original_dst_len;

	d = 0;
	while (d < dstsize)
	{
		if (dst[d] == '\0')
			break ;
		d++;
	}
	if (d == dstsize)
		return (d + ft_strlen(src));
	original_dst_len = d;
	s = 0;
	while (d < dstsize - 1)
	{
		if (src[s] == '\0')
			break ;
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (original_dst_len + ft_strlen(src));
}
