/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:00 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 01:29:34 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_string.h
  Strings related functions. Part of libft library.
*/

#ifndef FT_STRING_H
# define FT_STRING_H

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
 * @param [out] dst - .TODO.
 *
 * @param [in] src - .TODO.
 *
 * @param [in] dstsize - .TODO.
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
 * @param [in,out] dst - .TODO.
 *
 * @param [in] src - .TODO.
 *
 * @param [in] dstsize - .TODO.
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
 * @param [in] haystack - .TODO.
 *
 * @param [in] needle - .TODO.
 *
 * @param [in] len - .TODO.
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
 * @brief <b>ft_strmapi</b> -- Obtain a new string resulting from applying a
 * funtion to each char of a source string.
 *
 * @details Applies the function ’f’ to each character of the string ’s’, and
 * passing its index as first argument to create a new string (with malloc())
 * resulting from successive applications of ’f’.
 * 
 * @param [in] s - The source string.
 *
 * @param [in] f - The function to be applied to each character of the string
 * in the form "char f(unsigned int index, char c)" to produce the new string.
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
 * @param [in,out] s - The string to be modified.
 *
 * @param [in] f - The function to be applied to each character of the string
 * in the form "char f(unsigned int index, char *c)" to produce the new string.
 *
 * @warning A NULL pointer parameter or a non-terminated string are supposed to
 * make this function crash.
 *
 * @remark Implementation notes:  
 * TODO.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief <b>ft_atoi</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] str - The string containing a number.
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
 * @brief <b>ft_itoa</b> -- Converts int to string representation.
 *
 * @details Allocates (with malloc()) and returns a string representing the
 * integer received as an argument.  
 * Negative numbers must be handled.
 * 
 * @param [in] n - The integer value to be converted to a string (base 10).
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
 * @brief <b>ft_itoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] n - The integer value to be converted to a string in base format.
 *
 * @param [in] base - The base according to which the string number will be
 * constructed.
 *
 * @param [in] in_caps - If base 16, when != 0 uses abcdef instead of ABCDEF.
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
 * @brief <b>ft_ltoa_b</b> -- .TODO.
 *
 * @details Some_detailed_description.TODO.
 * 
 * @param [in] n - The long value to be converted to a string in base format.
 *
 * @param [in] base - The base according to which the string number will be
 * constructed.
 *
 * @param [in] in_caps - If base 16, when != 0 uses abcdef instead of ABCDEF.
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
 * @param [in] n - The long value to be converted to a string (base 10).
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
 * @param [in] n - The positive long value to be converted to a string in
 * base format.
 *
 * @param [in] base - The base according to which the string number will be
 * constructed.
 *
 * @param [in] in_caps - If base 16, when != 0 uses abcdef instead of ABCDEF.
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
 * @param [in] n - The positive integer value to be converted to a string in
 * base format.
 *
 * @param [in] base - The base according to which the string number will be
 * constructed.
 *
 * @param [in] in_caps - If base 16, when != 0 uses abcdef instead of ABCDEF.
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
 * @brief <b>ft_printf</b> -- Formated output conversion (partial printf()).
 *
 * @details The ft_printf() function partially implements the C standard library
 * printf() function.  
 * This implementation fully (and only) supports:  
 * Conversions: %c, %s, %p, %i, %d, %u, %x, %X, and %%.  
 * Flags: Any combination, in any order of "-0# +".  
 * '-' Left-justify within the given field width (right is the default).  
 * '0' Left-pads the number with zeroes (0) instead of spaces when
 * padding is specified.  
 * '#' Used with x or X specifiers the value is preceeded with 0x or 0X
 * respectively for values different than zero.  
 * ' ' A blank should be left before a positive number produced by a
 * signed conversion.  
 * '+' A sign must always be placed before a number produced by a
 * signed conversion.  
 * Width: Minimum field width. If the converted value has fewer characters than
 * the field width, it will be padded with spaces.  
 * Precision: Minimum number of digits to appear for d, i, u, x, and X
 * conversions. Or the maximum number of characters to be printed from a string
 * for s conversions.  
 * The syntax for a conversion is: %[flags][width][.precision]specifier  
 * For example:  
 * ft_printf("Int conversion of %0+5.3i as an example\n", foo);  
 * This is: Integer conversion, field width 5, precision 3, + sign,
 * and zero-padding.  
 * See printf(3) man page for details.
 *
 * @param [in] str - The format string including conversion specifiers.
 *
 * @param [in] ... - Values consistent (in type, number and order) with the
 * conversion specifiers included in format string.  
 *
 * @return If successful, ft_printf() returns the numbers of printed chars.  
 * If there is an error, it returns a -1 value.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), free(), write(), va_start(),
 * va_arg(), va_copy(), va_end().  
*/
int		ft_printf(const char *str, ...);

/**
 * @brief <b>ft_aisi</b> -- Checks if an ASCII c-string is a valid integer.
 * 
 * @details The ft_aisi() function receives a NUL terminated C-string and checks
 * if it is a valid representation of an integer value according to: first
 * character must be a '-', '+' or a digit; the remaining characters must be
 * digits (0-9); and the numeric value the string represents must lie within
 * INT_MIN and INT_MAX as defined in limits.h.  
 * This function is more strict than ft_atoi()'s requirements for a valid int.
 * Strings "+0" and "-0" are considered valid and equivalent to "0".
 *
 * @param [in] str - The string to analyze.
 *
 * @return A non-zero value if the string str is a valid representation of an
 * integer type.
 * 
 * @warning EXTERNAL FUNCTION USED: malloc() via ft_itoa() and free().
 *
 * @remark Implementation notes:  
 * It first check if first char is not a digit nor a sign, OR if the string is
 * empty. Second, it checks if there is a digit after a possible sign. Then
 * checks every character behind an optional sign for non-digit. Finally, this
 * function checks, char by char after possible sign, if the number inside the
 * string lies withing INT_MIN and INT_MAX as defined in limits.h.
 */
int		ft_aisi(const char *str);

/**
 * @brief <b>ft_is_string_composed_of_char</b> -- Checks if a string is solely
 * compose of a character.
 * 
 * @details The ft_is_string_composed_of_char function receives a NUL terminated
 * C-string and checks if it has no other character different than the passed
 * character.
 *
 * @param [in] str - The not NULL string to analyze.
 *
 * @param [in] c - The character to evaluate.
 *
 * @return A non-zero value if the string str is composed of the passed char.
 */
int		ft_is_string_composed_of_char(char *str, char c);

#endif
