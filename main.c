/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/12 17:19:19 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
:u

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
	return (0);
}
