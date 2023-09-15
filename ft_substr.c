/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:08 by lluque            #+#    #+#             */
/*   Updated: 2023/09/15 17:13:05 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_val;

	ret_val = malloc((len + 1) * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_strlcpy(ret_val, s + start, len + 1);
	return (ret_val);
}
