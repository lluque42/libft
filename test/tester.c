/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:55:05 by lluque            #+#    #+#             */
/*   Updated: 2024/01/27 22:55:27 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	ft_putendl_fd("La longitud de este string es: ", 0);
	ft_putendl_fd(ft_itoa(ft_strlen("La longitud de este string es: ")), 0);
	return (0);
}
