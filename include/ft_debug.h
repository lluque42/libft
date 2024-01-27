/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:22 by lluque            #+#    #+#             */
/*   Updated: 2024/01/25 01:20:46 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_debug.h
  Debugging related functions. Part of libft library.
*/

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

/**
 * @brief <b>ft_print_memory</b> -- Prints memory content from starting address.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] addr - The starting address.
 *
 * @param [in] size - The number of consecutive memory bytes to show from addr.
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), write().  
 * TODO.
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	*ft_print_memory(void *addr, unsigned int size);

#endif
