/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_blanks_strarr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:05:58 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 00:09:02 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_remove_blanks_strarr(char ***strarr, char blank_char)
{
	int		i;
	int		k;
	char	**result;

	i = -1;
	k = -1;
	result = ft_calloc(ft_strarrlen(*strarr) + 1, sizeof (char *));
	if (result == NULL)
		return ;
	while ((*strarr)[++i] != NULL)
	{
		if (ft_is_string_composed_of_char((*strarr)[i], blank_char))
			continue ;
		result[++k] = ft_strdup((*strarr)[i]);
	}
	ft_free_strarr(*strarr);
	*strarr = result;
}
