/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:23:53 by lluque            #+#    #+#             */
/*   Updated: 2024/07/21 01:24:47 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_free_gnl(int fd)
{
	char	*line;

	line = ft_gnl(fd);
	while (line != NULL)
	{
		free(line);
		line = ft_gnl(fd);
	}
}
