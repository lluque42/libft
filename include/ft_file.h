/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:38 by lluque            #+#    #+#             */
/*   Updated: 2024/07/21 01:26:37 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_file.h
  File manipulation related functions. Part of libft library.
*/

#ifndef FT_FILE_H
# define FT_FILE_H

/**
 * @brief <b>ft_putchar_fd</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] c - The character to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 * @warning EXTERNAL FUNCTION USED: write().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief <b>ft_putstr_fd</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] s - The c-string to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 * @warning EXTERNAL FUNCTION USED: write(). 
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief <b>ft_putendl_fd</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] s - The c-string to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 * @warning EXTERNAL FUNCTION USED: write().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief <b>ft_putnbr_fd</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] n - The integer value to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 *
 * @warning EXTERNAL FUNCTION USED: write().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief <b>ft_putchar_fd_safe</b> -- TODO..
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] c - The character to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 * @return Number of chars actually printed.
 *
 * @warning EXTERNAL FUNCTION USED: write().  
 * TODO.
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
int		ft_putchar_fd_safe(char c, int fd);

/**
 * @brief <b>ft_putstr_fd_safe</b> -- TODO.
 *
 * @details Some_detailed_description. TODO.
 * 
 * @param [in] s - The c-string to write.
 *
 * @param [in] fd - The valid file descriptor to write to.
 *
 * @return Number of chars actually printed.
 *
 * @warning EXTERNAL FUNCTION USED: write().  
 * TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
int		ft_putstr_fd_safe(char *s, int fd);

/**
 * @brief <b>ft_gnl</b> -- Get next line from file descriptor.
 *
 * @details Get next line function is used to read complete lines from a valid
 * file descriptor passed as argument. When there are no more lines to read or
 * some error occured, a NULL pointer is returned.  
 * The typical use of ft_gnl() is in a loop to read every line from the file
 * descriptor until the function returns NULL.
 * 
 * @param [in] fd - An int value representing the file descriptor to read from.
 *
 * @return A NUL terminated c-string with the next line read.  
 * NULL if error or no more lines available.
 *
 * @warning EXTERNAL FUNCTION USED: read(), malloc(), free().  
 *
 * @remark Implementation notes:  
 * This function can be used to read from multiple file descriptors while
 * maintaning consistence.
*/
char	*ft_gnl(int fd);

/**
 * @brief <b>ft_free_gnl</b> -- Frees allocated memory by ft_gnl() related
 * to previous calls on a specific file descriptor.
 *
 * @details After calling for the first time ft_gnl() on a file descriptor,
 * memory is allocated indirectly associated to its static variable. If
 * the caller doesn't keep calling ft_gnl() until it returns NULL, that memory
 * is never freed and it is reported by Valgrind as a "still reachable" pseudo
 * leak. The ft_free_gnl() function solves that by calling ft_gnl() on the
 * file descriptor until it returns NULL, while freeing every returned line
 * in the mean time. Note that if ft_gnl() is called on more than one file
 * descriptor this function must also be called on them.
 * 
 * @param [in] fd - An int value representing the file descriptor to read from.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
*/
void	ft_free_gnl(int fd);

#endif
