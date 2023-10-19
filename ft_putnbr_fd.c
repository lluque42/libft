/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:47:21 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 19:30:48 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFER_SIZE 11

void	ft_putnbr_fd(int n, int fd)
{	
	char	buffer[BUFFER_SIZE];
	int		offset;
	int		size;
	long	nb_abs;

	nb_abs = n;
	if (nb_abs < 0)
		nb_abs = nb_abs * -1;
	offset = BUFFER_SIZE - 1;
	size = 0;
	while (nb_abs > 9)
	{
		buffer[offset] = nb_abs - ((nb_abs / 10) * 10) + '0';
		offset--;
		size++;
		nb_abs = nb_abs / 10;
	}
	buffer[offset] = nb_abs + '0';
	size++;
	if (n < 0)
		write(fd, "-", 1);
	write(fd, buffer + offset, size);
	return ;
}
