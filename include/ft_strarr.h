/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:00 by lluque            #+#    #+#             */
/*   Updated: 2024/07/21 01:07:25 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strarr.h
 * Functions related to char **argv style arrays, that is, NULL terminated
 * arrays of c-strings. Part of libft library.
*/

#ifndef FT_STRARR_H
# define FT_STRARR_H

/**
 * @brief <b>ft_putstrarr_fd</b> -- Writes an argv-style string array to a
 * file descriptor
 *
 * @details This function outputs to a file descriptor each string in a
 * string array (argv-style) in a new line until finding a NULL.
 * 
 * @param [in] strarr - The argv-style NULL terminated array of c-strings.
 *
 * @param [in] fd - A valid file descriptor to which the argv-style NULL
 * terminated array of c-strings will be output.
 *
 * @warning A NULL pointer parameter, non-terminated array, or  non-terminated
 * c-strings will make this function crash.  
 * Uses write().
*/
void	ft_putstrarr_fd(char **strarr, int fd);

/**
 * @brief <b>ft_free_strarr</b> -- Frees the memory allocated for an argv-style
 * string array and its strings.
 *
 * @details Frees the allocated memory for every string and for the array of
 * an argv-style NULL terminated array of c-strings.
 * 
 * @param [in] strarr - The argv-style NULL terminated array of c-strings.
 *
 * @warning A NULL pointer parameter, non-terminated array, or  non-terminated
 * c-strings will make this function crash.  
 * Uses free().
*/
void	ft_free_strarr(char **strarr);

/**
 * @brief <b>ft_strarrlen</b> -- Obtains the number of strings in an argv-style
 * string array.
 *
 * @details Counts the strings in an argv-style NULL-terminated strings array
 * until a NULL is found.
 * 
 * @param [in] strarr - The argv-style NULL terminated array of c-strings.
 *
 * @return The length of the string.
 *
 * @warning A NULL pointer parameter, non-terminated array, or  non-terminated
 * c-strings will make this function crash. 
*/
int		ft_strarrlen(char **strarr);

/**
 * @brief <b>ft_remove_blanks_strarr</b> -- Remove strings composed only of
 * blank characters from the string array.
 *
 * @details Allocates memory for a new argv-style NULL-terminated array of
 * strings consisting of newly allocated strings which are copies
 * of those strings that are not composed solely of the blank_char.  
 * This allows, for example when used on parsing, to remove those strings that
 * are nothing more than a bunch of spaces.
 * 
 * @param [in, out] strarr - The argv-style NULL terminated array of c-strings. 
 * It is the responsibility of the caller to free the newly allocated strarr.
 *
 * @param [in] blank_char - The character to be considered as blank (e.g. ' ').
 *
 * @warning A NULL pointer parameter, non-terminated array, or  non-terminated
 * c-strings will make this function crash.  
 * Uses malloc(), free().
*/
void	ft_remove_blanks_strarr(char ***strarr, char blank_char);

/**
 * @brief <b>ft_free_strarr_from</b> -- Frees the memory allocated for the
 * strings of an argv-style string array from the element indicated by its
 * index in the array.
 *
 * @details Frees the allocated memory for every string starting at index
 * 'from' of an argv-style NULL terminated array of c-strings. Every pointer
 * of freed string is set to NULL. If from == 0, the behavior of this function
 * is the same as ft_free_strarr(), that is, in this case it would also free
 * the char** strarr.
 *
 * @param [in] strarr - The argv-style NULL terminated array of c-strings.
 *
 * @param [in] from - The index in the array of the first string to free.
 *
 * @warning A NULL pointer parameter; non-terminated array; non-terminated
 * c-strings; or invalid from value will make this function crash.  
 * Uses free().
*/
void	ft_free_strarr_from(char **strarr, int from);

#endif
