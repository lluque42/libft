/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:41:10 by lluque            #+#    #+#             */
/*   Updated: 2023/11/22 15:20:08 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * Public header file for libft library.
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/**
 * @brief <b>t_list</b> -- Typedef struct for a dynamic list node
 *
 * @details This type is used as a node for a one-way dynamic list. Any node 
 * could serve  as a list for itself (i.e. as the beginning of a list).
 *
 * @param content - Pointer to void to allow caller to use arbitrary type.
 *
 * @param next - Pointer to next node of the list. NULL if last node.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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
 * 		'\t'	'\n'	'\v'	'\f'	'\r'	' '
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
 * @return - None.
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

/**
 * @brief <b>ft_strlen</b> -- Gets length of a nul-terminated C string.
 *
 * @details Counts characters (from left to right) before the NUL
 * character '\0'.
 * 
 * @param [in] s - The nul-terminated C string.
 *
 * @return The length of the string.
 *
 * @warning A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. 
*/
size_t	ft_strlen(const char *s);

/**
 * @brief <b>ft_strlcpy</b> -- Copies a string.
 *
 * @details ft_strlcpy() copies up to dstsize - 1 characters from the string
 * src to dst, NUL-terminating the result if dstsize is not 0.  
 * ft_strlcpy() and ft_strlcat() take the full size of the destination buffer
 * and guarantee NUL-termination if there is room.  
 * Note that room for the NUL should be included in dstsize.
 * 
 * @param  - .TODO.
 *
 * @return ft_strlcpy() and ft_strlcat() functions return the total length of
 * the string they tried to create.  
 * For strlcpy() that means the length of src.  
 * For strlcat() that means the initial length of dst plus the length of src.
 *
 * @warning TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * When a 0 dstsize is passed it must not copy any chars. This must be checked
 * separately to avoid entering the while loop because the expression:  
 * i < dstsize - 1  
 * Does not work because of the unsignedness of dstsize. This worked:  
 * while (dstsize != 0 && i < dstsize - 1 && src[i] != '\0').
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief <b>ft_strlcat</b> -- Concatenate string.
 *
 * @details ft_strlcat() appends string src to the end of dst. It will append
 * at most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
 * unless dstsize is 0 or the original dst string was longer than dstsize
 * (in practice this should not happen as it means that either dstsize is
 * incorrect or that dst is not a proper string).  
 * ft_strlcpy() and ft_strlcat() take the full size of the destination buffer  
 * and guarantee NUL-termination if there is room.  
 * Note that room for the NUL should be included in dstsize.
 * 
 * @param  - .TODO.
 *
 * @return ft_strlcpy() and ft_strlcat() functions return the total length of
 * the string they tried to create.  
 * For strlcpy() that means the length of src.  
 * For strlcat() that means the initial length of dst plus the length of src.
 *
 * @warning TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * It must NOT be assumed that src is NUL terminated.  
 * It must NOT be assumed that dst is NUL terminated. First it must be
 * checked (within dstsize) that a '\0' is found in dst. If no NUL character
 * is found, the function must return inmediately without modifying dst (it
 * would make no sense otherwise because there is no way of knowing where
 * is the end of dst).  
 * If there is a NUL char in dst, then the copy from source can start.  
 * The copy of chars from src to dst is done while (d < dstsize - 1) but can
 * be aborted if (src[s] == '\0') (d starts at the position where '\0' is
 * found in dst; s starts at 0). Finally dst is ALWAYS NUL terminated, either
 * at position dstsize - 1 (i.e. the case when src doesn't really fit inside
 * dst) or when corresponding given the break of the while loop triggered by
 * the if (src[s] == '\0').  
 * Notice that src might not be NUL terminated. The concatenation would end  
 * only when !(d < dstsize - 1).  
 * In every case the return is:  
 * TODO  
 * In this case there are two possibilities:  
 * There is room for the whole src to fit + NUL char to fit in dst (always
 * according to dstsize and the actual position of the first NUL character
 * in dst); or  
 * TODO  
 * When a 0 (or negative) dstsize is passed it must not copy any chars.
 * This is a problem when evaluating the if condition because size_t is
 * unsigned and must be casted with (signed) in order for the condition to
 * behave as expected.  
 * Also, the returned value is NOT the original dst size + ft_strlen(src) but
 * dstsize parameter + ft_strlen(src).
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief <b>ft_strchr</b> -- Locate character in string (left to right).
 *
 * @details The ft_strchr() function locates the first occurrence of c
 * (converted to a char) in the string pointed to by s. The terminating null
 * character is considered to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.  
 * The strrchr() function is identical to strchr(), except it locates the
 * last occurrence of c.
 * 
 * @param [in] s - The string that will be scanned.
 *
 * @param [in] c - The char to look for in s.
 *
 * @return The functions ft_strchr() and ft_strrchr() return a pointer to the
 * located character, or NULL if the character does not appear in the string.
 *
 * @warning TODO. A NULL pointer parameter or a non-terminated string are
 * supposed to make this function crash.
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief <b>ft_strrchr</b> -- Locate character in string (right to left).
 *
 * @details The ft_strchr() function locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.  The terminating null
 * character is considered to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.  
 * The strrchr() function is identical to strchr(), except it locates the
 * last occurrence of c.
 * 
 * @param [in] s - The string that will be scanned.
 *
 * @param [in] c - The char to look for in s.
 *
 * @return The functions ft_strchr() and ft_strrchr() return a pointer to the
 * located character, or NULL if the character does not appear in the string.
 *
 * @warning TODO. A NULL pointer parameter or a non-terminated string are
 * supposed to make this function crash.
*/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief <b>ft_strncmp</b> -- Compare two strings.
 *
 * @details The ft_strcmp() function compares the two strings s1 and s2. The
 * comparison is done using unsigned characters.
 * 
 * @param [in] s1 - First string.
 *
 * @param [in] s2 - Second string.
 *
 * @param [in] n - Amount of bytes to compare from.
 *
 * @return Returns an integer indicating the result of the comparison, as
 * follows:  
 * 0, if the s1 and s2 are equal;  
 * A negative value if s1 is less than s2;  
 * A positive value if s1 is greater than s2.  
 * Specifically the returned value comes from the first different char found as
 * the difference between the numeric value of s1's char minus the numeric
 * value of s2's char.
 *
 * @warning TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief <b>ft_strnstr</b> -- Locate a substring in a string.
 *
 * @details The ft_strnstr() function locates the first occurrence of the
 * null-terminated string needle in the string haystack, where not more than
 * len characters are searched.  Characters that appear after a `\0' character
 * are not searched.
 * 
 * @param  - .TODO.
 *
 * @return If needle is an empty string, haystack is returned.  
 * If needle occurs nowhere in haystack, NULL is returned.  
 * Otherwise a pointer to the first character of the first occurrence of needle
 * is returned.
 *
 * @warning TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief <b>ft_atoi</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return TODO.
 *
 * @warning TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
int		ft_atoi(const char *str);

/**
 * @brief <b>ft_strdup</b> -- Saves a copy of a string.
 *
 * @details The ft_strdup() function allocates sufficient memory for a copy of
 * the string s1, does the copy, and returns a pointer to it.  
 * The pointer may subsequently be used as an argument to the function free().
 * 
 * @param [in] s1 - The string to be copied.
 *
 * @return If successful, ft_strdup() function returns a pointer to the newly
 * allocated string copy.  
 * If there is an error, it returns a NULL pointer.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
*/
char	*ft_strdup(const char *s1);

/**
 * @brief <b>ft_substr</b> -- Create new substring from original string.
 *
 * @details Allocates (with malloc()) and returns a substring from the string
 * ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param [in] s - The string from which to create the substring.
 *
 * @param [in] start - The start index of the substring in the string ’s’.
 *
 * @param [in] len - The maximum length of the substring.
 *
 * @return The newly allocated substring.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.TODO
 *
 * @remark Implementation notes:  
 * Before starting the copy of the substr, the following must be addressed:  
 * 1 If s = "" or start >= ft_strlen(s), it'd only make sense to return ""  
 * 2 If (start + len > ft_strlen(s)) len must be modified to
 * len = ft_strlen(s) - start before allocating memory for the substring.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief <b>ft_strjoin</b> -- Concatenates two strings resulting in new string.
 *
 * @details Allocates (with malloc()) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param [in] s1 - First string (prefix).
 *
 * @param [in] s2 - Second string (suffix).
 *
 * @return The new string.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief <b>ft_strtrim</b> -- Trims string resulting in new string.
 *
 * @details Allocates (with malloc()) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of s1
 * string. Parameter s1 is scanned left to right and right to left removing
 * any character that is also found in set until a character NOT included in
 * set is found.
 * 
 * @param [in] s1 - The string to be trimmed.
 *
 * @param [in] set - The string containing the chars that will be trimmed
 * from s1.
 *
 * @return The trimmed string.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief <b>ft_split</b> -- Split string according to delimiter char.
 *
 * @details Allocates (with malloc(3)) and returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter.  
 * The array must end with a NULL pointer.
 * 
 * @param [in] s - The string to be splitted.
 *
 * @param [in] c - The character that will act as delimiter to determine the
 * resulting splitted substrings.
 *
 * @return 	The array of new strings resulting from the split. The last element
 * of this array is always NULL.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), free().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * Contigous delimiter chars produce no substrings at all.  
 * This function is supposed to return a single element array (with NULL value)
 * when argument s is an empty string.
*/
char	**ft_split(char const *s, char c);

/**
 * @brief <b>ft_itoa</b> -- Converts int to string representation.
 *
 * @details Allocates (with malloc()) and returns a string representing the
 * integer received as an argument.  
 * Negative numbers must be handled.
 * 
 * @param  - .TODO.
 *
 * @return 	The string representing the integer.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_itoa(int n);

/**
 * @brief <b>ft_ltoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @param in_caps - If hexadecimal, when != 0 uses abcdef instead of ABCDEF.
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_itoa_b(int n, unsigned int base, int in_caps);

/**
 * @brief <b>ft_get_sym_table</b> -- TODO.
 *
 * @details Some_detailed_description.TODO
 * 
 * @param  - .TODO
 *
 * @return TODO
 *
 * @warning TODO
 *
 * @remark Implementation notes:  
 * TODO
*/
char	*ft_get_sym_table(char *sym_table, unsigned int base, int in_caps);

/**
 * @brief <b>ft_ltoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_ltoa_b(long n, unsigned int base, int in_caps);

/**
 * @brief <b>ft_ltoa</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_ltoa(long n);

/**
 * @brief <b>ft_ultoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed to make
 * this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_ultoa_b(unsigned long n, unsigned int base, int in_caps);

/**
 * @brief <b>ft_uitoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return TODO.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_uitoa_b(unsigned int n, unsigned int base, int in_caps);

/**
 * @brief <b>ft_strmapi</b> -- Apply a funtion to each char of a string.
 *
 * @details Applies the function ’f’ to each character of the string ’s’, and
 * passing its index as first argument to create a new string (with malloc())
 * resulting from successive applications of ’f’.
 * 
 * @param  - .TODO.
 *
 * @return The string created from the successive applications of ’f’.  
 * Returns NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash. TODO
 *
 * @remark Implementation notes:  
 * TODO.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief <b>ft_striteri</b> -- Modify a string applying a function to each of 
 * its chars.
 *
 * @details Applies the function ’f’ on each character of the string passed as
 * argument, passing its index as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 * 
 * @param  - .TODO.
 *
 * @return None.
 *
 * @warning A NULL pointer parameter or a non-terminated string are supposed to
 * make this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief <b>ft_putchar_fd</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return TODO.
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
 * @param  - .TODO.
 *
 * @return TODO.
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
 * @param  - .TODO.
 *
 * @return TODO.
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
 * @param  - .TODO.
 *
 * @return TODO.
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
 * @brief <b>ft_pow</b> -- Power function.
 *
 * @details The pow() functions compute base raised to the power exp.
 * 
 * @param  - .TODO.
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
 * @brief <b>ft_print_memory</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
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

/**
 * @brief <b>ft_putchar_fd_safe</b> -- TODO..
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param  - .TODO.
 *
 * @return Amount of chars actually printed.
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
 * @param  - . TODO
 *
 * @return Amount of chars actually printed.
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
 * @brief <b>ft_lstnew</b> -- Create a list element from pointer to its content.
 *
 * @details Allocates (with malloc()) and returns a new node.  
 * The member variable ’content’ is initialized with the value of the parameter
 * ’content’. The variable ’next’ is initialized to NULL.
 * 
 * @param [in] content - The content to create the node with.
 *
 * @return The new node.
 *
 * @warning EXTERNAL FUNCTION USED: ???.  
 * TODO.  
 * A NULL pointer parameter or a non-terminated string are supposed
 * to make this function crash.
 *
 * @remark Implementation notes:  
 * If content == NULL, must return NULL.  
 * If malloc fails, must return NULL.
 *
*/
t_list	*ft_lstnew(void *content);

/**
 * @brief <b>ft_lstadd_front</b> -- Adds node at the beginning of the list.
 *
 * @details Adds the node ’new’ at the beginning of the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first link of a list.
 *
 * @param [in] new - The address of a pointer to the node to be added to the 
 * list.
 *
 * @return None.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * TODO
 *
 * @remark Implementation notes:  
 * lst == NULL.  
 * *lst == NULL.  
 * t_list == NULL.  
 * TODO.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief <b>ft_lstsize</b> -- Counts the number of nodes in a list.
 *
 * @details Counts the number of nodes in a list.
 * 
 * @param [in] lst - The beginning of the list.
 *
 * @return The length of the list.
 *
 * @warning TODO.
 *
 * @remark Implementation notes:  
 * If lst == NULL, return value must be 0. 
*/
int		ft_lstsize(t_list *lst);

/**
 * @brief <b>ft_lstlast</b> -- Returns the last node of the list.
 *
 * @details Returns the last node of the list.
 * 
 * @param [in] lst - The beginning of the list.
 *
 * @return Last node of the list.
 *
 * @warning TODO.
 *
 * @remark Implementation notes:  
 * If lst == NULL, return value is NULL.
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief <b>ft_lstadd_back</b> -- Adds the node ’new’ at the end of the list.
 *
 * @details Adds the node ’new’ at the end of the list.
 * 
 * @param [in] lst - The address of a pointer to the first link of a list.
 *
 * @param [in] - The address of a pointer to the node to be added to the list.
 *
 * @return None.
 *
 * @warning TODO.
 *
 * @remark Implementation notes:  
 * If lst == NULL or new == NULL, nothing must be done.  
 * If *lst == NULL	>>	*lst = new (i.e. lstadd_backing an element to a NULL
 * list, creates the list with just that element).
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief <b>ft_lstdelone</b> -- Deletes and frees memory of item list and its 
 * content.
 *
 * @details Takes as a parameter a node and frees the memory of the node’s
 * content using the function ’del’ given as a parameter and free the node.  
 * The memory of ’next’ must not be freed.
 * 
 * @param [in] lst - The node to free.
 *
 * @param [in] del - The address of the function used to delete the content.
 *
 * @return None.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
 * TODO.
 *
 * @remark Implementation notes:  
 * CONCEPTUAL: Could break a list because no first item of list nor previous
 * item is given. This is the expected behavior.  
 * The caller should set lst to NULL after freeing the memory with this
 * funcion.  
 * Function del() must handle NULL content but must not free the node.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief <b>ft_lstclear</b> -- Deletes and frees given node and succesors.
 * (freeing contents).
 *
 * @details Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free().  
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param [in,out] lst- The address of a pointer to a node.
 *
 * @param [in] del - The address of the function used to delete the content
 * of the node.
 *
 * @return None.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
 * TODO.
 *
 * @remark Implementation notes:  
 * If lst == NULL, nothing must be done.  
 * If *lst == NULL, nothing must be done.  
 * Parameter lst MUST be set to NULL by this function.  
 * Function del() must handle NULL content but must not free the node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief <b>ft_lstiter</b> -- Applies function f to the content of each node
 * on list.
 *
 * @details Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node.
 * 
 * @param lst - The address of a pointer to a node.
 *
 * @param f - The address of the function used to iterate on the list.
 *
 * @return None.
 *
 * @warning TODO.
 *
 * @remark Implementation notes:  
 * If lst == NULL, return NULL.  
 * CONCEPTUAL: f fuction must handle NULL content: f() must return NULL, also
 * if its malloc() call	fails. f() must return the address of the new content.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief <b>ft_lstmap</b> -- Returns new list based on applying f to each
 * nodes content.
 *
 * @details Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node. Creates a new list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to delete the content of a node
 * if needed.
 * 
 * @param lst - The address of a pointer to a node.
 *
 * @param f - The address of the function used to iterate on the list.
 *
 * @param del - The address of the function used to delete the content of a
 * node if needed.
 *
 * @return The new list.  
 * NULL if the allocation fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), free().  
 * TODO.
 *
 * @remark Implementation notes:  
 * CONCEPTUAL: f fuction must handle NULL content: f() must return NULL, also
 * if its malloc() call	fails. f() must return the address of the new content.  
 * Function del() must handle NULL content but must not free the node.  
 * If at some point the funcion fails, the in-construction new list must be
 * cleared completely and NULL must be returned.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
