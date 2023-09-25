/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:08 by lluque            #+#    #+#             */
/*   Updated: 2023/09/25 23:24:45 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_val;
	size_t	ret_val_size;

	if (start > ft_strlen(s) + 1)
	{
		ret_val = malloc(sizeof (char));
		*ret_val = '\0';
		return (ret_val);
	}
	if (len > ft_strlen(s) - start)
		ret_val_size = ft_strlen(s) - start + 1;
	else
		ret_val_size = len + 1;
	ret_val = malloc((ret_val_size) * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_strlcpy(ret_val, s + start, len + 1);
	return (ret_val);
}
