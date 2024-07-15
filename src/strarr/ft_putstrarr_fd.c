/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:04:18 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 00:08:10 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putstrarr_fd(char **strarr, int fd)
{
	int	i;

	i = -1;
	while (strarr[++i] != NULL)
		ft_putendl_fd(strarr[i], fd);
}
