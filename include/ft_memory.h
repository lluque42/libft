/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:00 by lluque            #+#    #+#             */
/*   Updated: 2024/01/25 01:26:50 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memory.h
  Memory blocks manipulation functions. Part of libft library.
*/

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

/**
 * @brief <b>ft_memset</b> -- Fills memory with a constant byte.
 *
 * @details Writes len bytes with c (unsigned char casted) starting at b memory
 * position.
 *
 * @param [in,out] b - Pointer to first address.
 *
 * @param [in] c - Integer with the value (unsigned char casted) to write.
 *
 * @param [in] len - Bytes to be written.
 *
 * @return - The original pointer passed as function argument.
 *
 * @warning A NULL pointer parameter or an improper len (invasion of forbidden
 * memory space) are supposed to make this function crash. 
*/
void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief <b>ft_bzero</b> -- Fills memory with zeros.
 *
 * @details Writes n bytes with 0 starting at s memory position. Uses
 * ft_memset().
 *
 * @param [in,out] s - Pointer to first address.
 *
 * @param [in] n - Bytes to be written.
 *
 * @warning A NULL pointer parameter or an improper len (invasion of forbidden
 * memory space) are supposed to make this function crash. 
*/
void	ft_bzero(void *s, size_t n);

/**
 * @brief <b>ft_memcpy</b> -- Copies memory area (<b>overlapping unsafe</b>).
 *
 * @details The ft_memcpy() function copies n bytes from memory area src to
 * memory area dst.  
 * <b>If dst and src overlap, behavior is undefined</b>. Applications in which
 * dst and src might overlap should use ft_memmove() instead.
 *
 * @param [in,out] dst - Pointer to destination (start of memory to be written).
 *
 * @param [in] src - Pointer to source (address of first byte to copy).
 *
 * @param [in] n - Amount of bytes to be copied from src to dst.
 *
 * @return - The original value of pointer dst.
 *
 * @warning If dst and src are <b>both</b> NULL <b>or</b> n == 0, the function
 * <b>does nothing</b>, just returns dst.  
 * When n != 0 this function is supposed to fail <b>only if either src or dst
 * are NULL</b>.  
 * If dst and src overlap the <b>behaviour is undefined</b>.  
 * An improper n (invasion of forbidden memory space) is supposed to make this
 * function crash.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief <b>ft_memmove</b> -- Copies memory area (<b>overlapping safe</b>).
 * 
 * @details The ft_memmove() function copies len bytes from string src to
 * string dst.  
 * The two strings may overlap; the copy is always done in a non-destructive
 * manner.
 *
 * @param [in,out] dst - Pointer to destination (start of memory to be written).
 *
 * @param [in] src - Pointer to source (address of first byte to copy).
 *
 * @param [in] len - Amount of bytes to be copied from src to dst.
 *
 * @return - The original value of pointer dst.
 *
 * @warning If dst and src are <b>both</b> NULL <b>or</b> n == 0, the function
 * <b>does nothing</b>, just returns dst.  
 * When len != 0 this function is supposed to fail <b>only if either src or
 * dst are NULL</b>.  
 * An improper len (invasion of forbidden memory space) is supposed to make  
 * this function crash.
 *
 * @remark Implementation notes:  
 * If destination overlaps source, it is possible that at some point the
 * original data in source gets corrupted before it's been copied into dst.  
 * Problematic case:	If reading src from the beginning  
 * 						dst > src && src + len > dst  
 * 	0123456789012345678901234567  
 * 	ssssssssssssssssssssssss  
 * 		dddddddddddddddddddddddd  
 * 		In order to avoid this, src must be read from the end in this case.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief <b>ft_memchr</b> -- Locate byte in byte string.
 *
 * @details The ft_memchr() function locates the first occurrence of c
 * (converted to an unsigned char) in the first n bytes of string s.
 * 
 * @param [in] s - The start address for the search.
 *
 * @param [in] c - The byte to search for (interpreted as unsigned char).
 *
 * @param [in] n - The start address for the search.
 *
 * @return A pointer to the byte located.  
 * NULL if no such byte exists within n bytes or if n == 0.
 *
 * @warning A NULL pointer parameter is supposed to make this function crash.
 *
 * @remark Implementation notes:  
 * A n == 0 parameter is also supposed to return a NULL pointer.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief <b>ft_memcmp</b> -- Compare memory areas.
 *
 * @details The ft_memcmp() function compares the first n bytes (each
 * interpreted as unsigned char) of the memory areas s1 and s2.
 * 
 * @param [in] s1 - Address of first memory area.
 *
 * @param [in] s2 - Address of second memory area.
 *
 * @param [in] n - Amount of bytes to compare from.
 *
 * @return Returns a 0 if both memory area are equal or if n == 0.  
 * Returns a positive or negative number if different.  
 * Specifically the returned value comes from the first different byte found as
 * the difference between the numeric value of s1's byte minus the numeric
 * value of s2's byte.
 *
 * @warning NULL pointers parameters are supposed to make this function crash.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief <b>ft_calloc</b> -- Memory allocation.
 *
 * @details The ft_calloc() function contiguously allocates enough space for
 * count objects that are size bytes of memory each and returns a pointer to
 * the allocated memory.  The allocated memory is filled with bytes of value
 * zero.
 * 
 * @param [in] count - The number of objects.
 *
 * @param [in] size - The size in bytes of one object.
 *
 * @return If successful, ft_calloc() function returns a pointer to allocated
 * memory.  
 * If there is an error, it returns a NULL pointer.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().
*/
void	*ft_calloc(size_t count, size_t size);

#endif
