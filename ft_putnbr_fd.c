/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:47:21 by lluque            #+#    #+#             */
/*   Updated: 2023/09/17 10:21:25 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	char	*n_str;

	n_str = ft_itoa(n);
	size = ft_strlen(n_str);
	write(fd, n_str, size - 1);
	if (n_str != NULL)
		free(n_str);
}
