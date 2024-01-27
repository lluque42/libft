/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:53:08 by lluque            #+#    #+#             */
/*   Updated: 2024/01/25 01:14:49 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_char.h
  Char related functions. Part of libft library.
*/

#ifndef FT_CHAR_H
# define FT_CHAR_H

/**
 * @brief <b>ft_isupper</b> -- Tests for uppercase alphabetic character.
 *
 * @details Evaluate if c is an uppercase alphabetic character ('A' - 'Z').  
 * The value of the argument must be representable as an unsigned char or the 
 * value of EOF.
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is an uppercase alphabetic character.
*/
int		ft_isupper(int c);

/**
 * @brief <b>ft_islower</b> -- Tests for lowercase alphabetic character.
 *
 * @details Evaluate if c is a lowercase alphabetic character ('a' - 'z').
 * The value of the argument must be representable as an unsigned char or the 
 * value of EOF.
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is an lowercase alphabetic character.
*/
int		ft_islower(int c);

/**
 * @brief <b>ft_isalpha</b> -- Checks for an alphabetic character.
 *
 * @details Uses ft_isupper() and ft_islower() to evaluate if c is an alphabetic
 * character ('A' - 'Z' or 'a' to 'z').
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is an alphabetic character.
*/
int		ft_isalpha(int c);

/**
 * @brief <b>ft_isdigit</b> -- Checks for a digit character.
 *
 * @details Evaluate if c is a digit character ('0' - '9').
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is a digit character.
*/
int		ft_isdigit(int c);

/**
 * @brief <b>ft_issign</b> -- Checks for a '+' '-' character.
 *
 * @details Evaluate if c is a sign (i.e. any of '+' '-' characters).
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is a sign character (+1 for '+' or -1 for '-').  
 * Returns 0 if not a sign character.
*/
int		ft_issign(char c);

/**
 * @brief <b>ft_isalnum</b> -- Checks for an alphanumeric character.
 *
 * @details Uses ft_isalpha() and ft_isdigit() to evaluate if c is an
 * alphanumeric character ('A' - 'Z' or 'a' to 'z' or '0' to '9').
 *
 * @param [in] c - The character to evaluate.
 *
 * @return Non-zero value if c is an alphanumeric character.
*/
int		ft_isalnum(int c);

/**
 * @brief <b>ft_isascii</b> -- Checks for (basic) ASCII character.
 *
 * @details Checks if argument fits in 7-bit ASCII (basic, universal ASCII).
 * That is, from 00 to 0177 (decimal 0 to 127).
 * 
 * @param [in] c - The character to evaluate.
 *
 * @return 1 if c is an ASCII character; 0 otherwise.
*/
int		ft_isascii(int c);

/**
 * @brief <b>ft_isprint</b> -- Checks for printable (basic) ASCII character.
 *
 * @details Checks if argument fits in the range of 040 to 0176 (decimal 32 to
 * 126). That is, the printable characters range in 7 bits basic, universal
 * ASCII).
 * 
 * @param [in] c - The character to evaluate.
 *
 * @return 1 if c is an printable basic ASCII character; 0 otherwise.
*/
int		ft_isprint(int c);

/**
 * @brief <b>ft_isspace</b> -- White-space (in the broad sense) character test.
 *
 * @details The ft_isspace() function tests for the white-space characters.  
 * This includes the following standard characters:  
 * 		'\\t'	'\\n'	'\\v'	'\\f'	'\\r'	' '
 * 
 * @param [in] c - The character to evaluate.
 *
 * @return 1 if c is a white space in the broad sense; 0 otherwise.
*/
int		ft_isspace(int c);

/**
 * @brief <b>ft_toupper</b> -- If lowercase, changes to uppercase.
 *
 * @details If argument is a lowercase letter, this function returns its
 * uppercase version.
 *
 * @param [in] c - The character to evaluate.
 *
 * @return If argument char is lowercase, the return is its uppercase version.  
 * Otherwise the return is the original char c.
*/
int		ft_toupper(int c);

/**
 * @brief <b>ft_tolower</b> -- If uppercase, changes to lowercase.
 *
 * @details If argument is an uppercase letter, this function returns its
 * lowercase version.
 *
 * @param [in] c - The character to evaluate.
 *
 * @return If argument char is uppercase, the return is its lowercase version.  
 * Otherwise the return is the original char c.
*/
int		ft_tolower(int c);

#endif
