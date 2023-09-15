/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:23:39 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 03:26:18 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		return_value;

	i = 0;
	return_value = (unsigned char)s1[i] - (unsigned char)s2[i];
	while (return_value == 0 && i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		return_value = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (return_value);
}
