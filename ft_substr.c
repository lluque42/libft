/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:08 by lluque            #+#    #+#             */
/*   Updated: 2023/09/30 21:26:11 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_val;
	size_t	ret_val_size;

	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
	{
		ret_val = malloc(sizeof (char));
		if (ret_val == NULL)
			return (NULL);
		*ret_val = '\0';
		return (ret_val);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ret_val_size = len + 1;
	ret_val = malloc((ret_val_size) * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_strlcpy(ret_val, s + start, ret_val_size);
	return (ret_val);
}
