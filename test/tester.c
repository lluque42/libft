/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:55:05 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 17:50:31 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_nbr;	
	
	//ft_printf("El BUFFER_SIZE es %i\n", BUFFER_SIZE);

	if (argc == 1)
		fd = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("[main] Error al abrir el archivo '%s'\n", argv[1]);
			return (1);
		}
	}
	line_nbr = 1;
	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		ft_printf("[main][linea %d] '%s'\n", line_nbr, line);
		line_nbr++;
	}
	ft_printf("[main][linea %d] '%s'", line_nbr, line);
	close(fd);
	return (0);
}
