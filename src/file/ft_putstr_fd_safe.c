/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:40:46 by lluque            #+#    #+#             */
/*   Updated: 2023/11/13 12:11:40 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd_safe(char *s, int fd)
{
	int	i;
	int	bytes_written;

	i = 0;
	bytes_written = 0;
	while (s[i] != '\0')
	{
		bytes_written = ft_putchar_fd_safe(s[i], fd);
		if (bytes_written != 1)
			return (i);
		i++;
	}
	return (i);
}
