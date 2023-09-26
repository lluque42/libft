/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:03:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/26 22:00:25 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Remember from man page:
// 		Note that room for the NUL should be included in dstsize.
// It seems that size includes the NUL, while length doesn't.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	d;
	int	s;
	int	original_dst_len;

	original_dst_len = ft_strlen(dst);
	d = original_dst_len;
	s = 0;
	while (d < (signed)dstsize - 1 && src[s] != '\0')
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	if (!(dstsize == 0 || original_dst_len > (signed)dstsize))
		dst[d] = '\0';
	return (dstsize + ft_strlen(src));
}
