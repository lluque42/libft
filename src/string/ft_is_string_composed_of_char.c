/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_string_composed_of_char.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:23:36 by lluque            #+#    #+#             */
/*   Updated: 2024/07/15 22:24:22 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_string_composed_of_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != c)
			return (0);
	}
	return (1);
}
