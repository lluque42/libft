/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:05:23 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 00:05:46 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_strarr(char **strarr)
{
	int	i;

	i = -1;
	while (strarr[++i] != NULL)
		free(strarr[i]);
	free(strarr);
}
