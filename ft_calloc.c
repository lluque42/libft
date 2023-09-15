/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:01:12 by lluque            #+#    #+#             */
/*   Updated: 2023/09/15 17:11:39 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_val;
	int		bytes;

	bytes = count * size;
	ret_val = malloc (bytes);
	if (ret_val == NULL)
		return (NULL);
	ft_bzero(ret_val, bytes);
	return (ret_val);
}
