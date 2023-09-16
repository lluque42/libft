/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/16 16:35:26 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	ft_prueba(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	return (' ');
}

void	ft_prueba2(unsigned int i, char *c)
{
	if (!(i % 2 == 0))
		*c = ' ';
}

int	main(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
		return (1);
	if (ft_isalpha(argv[1][0]))
		printf("'%c' es alpha\n", argv[1][0]);
	if (ft_isdigit(argv[1][0]))
		printf("'%c' es un digito\n", argv[1][0]);
	if (ft_isalnum(argv[1][0]))
		printf("'%c' es alfanumerico\n", argv[1][0]);
	ptr = malloc(5 * sizeof (char));
	ft_memset(ptr, argv[1][0], 4);
	ptr[4] = '\0';
	printf("El arreglo de memset quedo como: '%s'\n", ptr);
	printf("El resultado de ft_strmapi() sobre '%s' es '%s'\n", argv[1] , ft_strmapi(argv[1],ft_prueba));
	printf("El resultado de ft_striteri() sobre '%s' es:\n", argv[1]);
	
	int	len;
	int	i;
	i = 0;
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		ft_striteri(argv[1], ft_prueba2);
		i++;
	}
	printf("'%s'\n", argv[1]);
	
	return (0);
}
