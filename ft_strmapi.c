/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:40:26 by lluque            #+#    #+#             */
/*   Updated: 2023/09/16 14:56:27 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*ret_val;

	i = 0;
	len = ft_strlen(s);
	ret_val = malloc((len + 1) * sizeof (char));
	while (i < len)
	{
		ret_val[i] = f(i, s[i]);
		i++;
	}
	ret_val[i] = '\0';
	return (ret_val);
}
