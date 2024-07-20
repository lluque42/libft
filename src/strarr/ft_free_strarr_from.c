/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarr_from.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:37:42 by lluque            #+#    #+#             */
/*   Updated: 2024/07/21 00:47:25 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_strarr_from(char **str_arr, int from)
{
	int	i;

	i = from;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		str_arr[i] = NULL;
		i++;
	}
	if (from == 0)
		free(str_arr);
}
