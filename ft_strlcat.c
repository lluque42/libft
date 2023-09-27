/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:03:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/27 22:12:13 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

// Remember from man page:
// 		Note that room for the NUL should be included in dstsize.
// It seems that size includes the NUL, while length doesn't.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	d;
	int	s;
	int	original_dst_len;

	d = 0;
	while (d < (signed)dstsize)
	{
		if (dst[d] == '\0')
			break ;
		d++;
	}
	if (d == (signed)dstsize)
		return (d + ft_strlen(src));
	original_dst_len = d;
	s = 0;
	while (d < (signed)dstsize - 1)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (original_dst_len + ft_strlen(src));
}
