/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:17:32 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 02:21:44 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*return_value;

	return_value = (char *)s + ft_strlen(s);
	while (return_value >= s)
	{
		if (*return_value == (char)c)
			return (return_value);
		return_value--;
	}
	return (NULL);
}
