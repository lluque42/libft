/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:03:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 01:40:10 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Remember from man page:
// 		Note that room for the NUL should be included in dstsize.
// It seems that size includes the NUL, while length doesn't.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	original_dst_len;

	original_dst_len = ft_strlen(dst);
	d = original_dst_len;
	s = 0;
	while (d < dstsize - 1 && src[s] != '\0')
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	if (!(dstsize == 0 || original_dst_len > dstsize))
		dst[d] = '\0';
	return (d);
}
