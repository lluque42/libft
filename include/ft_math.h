/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:57:23 by lluque            #+#    #+#             */
/*   Updated: 2024/08/15 00:35:14 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_math.h
  Math related functions. Part of libft library.
*/

#ifndef FT_MATH_H
# define FT_MATH_H

/**
 * @brief <b>ft_pow</b> -- Power function.
 *
 * @details The pow() functions compute base raised to the power exp.
 * 
 * @param [in] base - The base as an integer value.
 *
 * @param [in] exp - The exponent as an unsigned int value.
 *
 * @return base^exp.
 *
 * @warning TODO.
 *
 * @remark Implementation notes:  
 * TODO.
*/
int		ft_pow(int base, unsigned int exp);

/**
 * @brief <b>ft_abs</b> -- Returns absolute value of int as long.
 * 
 * @param [in] value - Positive or negative integer.
 *
 * @return A long positive value that is the absolute value of passed integer.
 *
 * @warning ft_abs(INT_MIN) returns a positive value greater than INT_MAX.
 */
long	ft_abs(int value);

#endif
