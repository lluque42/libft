/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:32 by lluque            #+#    #+#             */
/*   Updated: 2023/10/03 12:46:05 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_isupper -- Test for uppercase

DESCRIPTION
	The isupper() function tests for any upper-case letter.
	The value of the argument must be representable as
	an unsigned char or the value of EOF.

PARAMETERS


RETURN VALUES
	The isupper() function returns zero if the character tests false and
	returns non-zero if the character tests true.

******PROBLEMS*******

*/
static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/*
NAME
	ft_islower -- Test for lowercase

DESCRIPTION
	The islower() function tests for any lower-case letters.
	The value of the argument must be representable as an unsigned char
	or the value of EOF.

PARAMETERS


RETURN VALUES
	The islower() function returns zero if the character tests false and
	returns non-zero if the character tests true.

******PROBLEMS*******

*/
static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) + ft_islower(c));
}
