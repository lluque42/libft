/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:41:10 by lluque            #+#    #+#             */
/*   Updated: 2023/09/16 12:00:47 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*
NAME
	ft_memcpy -- Copy memory area
DESCRIPTION
     The memcpy() function copies n bytes from memory area src to
	 memory area dst.  If dst and src overlap, behavior is undefined.
	 Applications in which dst and src might overlap should
	 use memmove(3) instead.
RETURN VALUES
     The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
NAME
    ft_memmove -- copy byte string
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
	 The two strings may overlap; the copy is always done in a
	 non-destructive manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
NAME
	ft_strchr, ft_strrchr -- locate character in string

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to
	 a char) in the string pointed to by s.  The terminating null character
	 is considered to be part of the string; therefore if c is `\0', the
     functions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the
	 last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
	 character, or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
NAME
	memchr -- locate byte in byte string

DESCRIPTION
	The memchr() function locates the first occurrence of c (converted to
	an unsigned char) in string s.

RETURN VALUES
	The memchr() function returns a pointer to the byte located,
	or NULL if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
NAME
	ft_strnstr -- locate a substring in a string
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated
	string needle in the string haystack, where not more than len characters
	are searched.  Characters that appear after a `\0' character
	are not searched.
RETURN VALUES
    If needle is an empty string, haystack is returned;
	if needle occurs nowhere in haystack, NULL is returned;
    otherwise a pointer to the first character of the first occurrence
	of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);

/*
NAME
	ft_calloc -- memory allocation
DESCRIPTION
	The calloc() function contiguously allocates enough space for
	count objects that are size bytes of memory each and returns a
	pointer to the allocated memory.  The allocated memory is
	filled with bytes of value zero.
RETURN VALUES
     If successful, calloc() function return a pointer to allocated memory.
	 If there is an error, they return a NULL pointer and set errno to ENOMEM.
*/
void	*ft_calloc(size_t count, size_t size);

/*
NAME	
	ft_strdup - Save a copy of a string
DESCRIPTION
    The strdup() function allocates sufficient memory for a copy of the
	string s1, does the copy, and returns a pointer to it.
	The pointer may subsequently be used as an argument to the function free(3).

    If insufficient memory is available, NULL is returned and errno is
	set to ENOMEM.
RETURN VALUES
	The new string
*/
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

/*
NAME
	ft_split -- Split string according to delimiter char
DESCRIPTION
	Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. 
	The array must end with a NULL pointer.
RETURN VALUES
	The array of new strings resulting from the split.
	NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c);

/*
NAME
	ft_itoa -- Converts int to string representation
DESCRIPTION
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.
RETURN VALUES
	The string representing the integer.
	NULL if the allocation fails.	
*/
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_issign(char c);
int		ft_exp(int base, int exp);

/*
NAME
	ft_strcount -- Counts ocurrences of char in string
DESCRIPTION
	Using ft_strchr...
RETURN VALUES
	The number of occurences
*/
int		ft_strcount(char const *s, char c);

/*
NAME
	ft_strextract -- Extracts the last part of string s

DESCRIPTION
	Returns a new string with the contents of s from position pos to NUL char
	(both included). Modifies original s by writing NUL chars from position
   	until original NUL char
	Returns NULL if allocation failed.

RETURN VALUES
	The new string
*/
char	*ft_strextract(char *s, size_t pos);
#endif
