/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:27:18 by lluque            #+#    #+#             */
/*   Updated: 2023/09/15 17:13:48 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_val;
	int		size;
	int		len1;

	len1 = ft_strlen(s1);
	size = len1 + ft_strlen(s2) + 1;
	ret_val = malloc(size * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_strlcpy(ret_val, s1, size);
	ft_strlcpy(ret_val + len1, s2, size - len1);
	return (ret_val);
}
