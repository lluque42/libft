/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:41:10 by lluque            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/08 11:35:02 by lluque           ###   ########.fr       */
=======
/*   Updated: 2023/11/11 08:39:06 by lluque           ###   ########.fr       */
>>>>>>> development
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// Struct for a dynamic list node
// Any node could serve as a list for itself (i.e. as the beginning of a list)
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
NAME
	--

DESCRIPTION


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_isalpha(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_isdigit(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_isalnum(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_isascii(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_isprint(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
size_t	ft_strlen(const char *s);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	*ft_memset(void *b, int c, size_t len);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	ft_bzero(void *s, size_t n);

/*
NAME
	ft_memcpy -- Copy memory area
DESCRIPTION
     The memcpy() function copies n bytes from memory area src to
	 memory area dst.  If dst and src overlap, behavior is undefined.
	 Applications in which dst and src might overlap should
	 use memmove(3) instead.

PARAMETERS
	

RETURN VALUES
     The memcpy() function returns the original value of dst.

******PROBLEMS*******
	If dst and src are both NULL or n == 0, the function does nothing and just
	returns dst.
	When n != 0 this function is supposed to fail if either src OR dst are NULL 
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
NAME
    ft_memmove -- copy byte string

DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
	 The two strings may overlap; the copy is always done in a
	 non-destructive manner.


PARAMETERS
	

RETURN VALUES
     The memmove() function returns the original value of dst.

******PROBLEMS*******
	If destination overlaps source, it is possible that at some point the
	original data in source gets corrupted before it's been copied into dst.
	Problematic case:	If reading src from the beginning
						dst > src && src + len > dst
	0123456789012345678901234567
	ssssssssssssssssssssssss
	    dddddddddddddddddddddddd
	In order to avoid this, src must be read from the end in this case
	
	If dst and src are both NULL or len == 0, the function does nothing and just
	returns dst.
	When len != 0 this function is supposed to fail if either src OR dst 
	are NULL 
	
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
NAME
	ft_strlcpy -- Copies a string

DESCRIPTION
	strlcpy() copies up to dstsize - 1 characters from the string src to dst,
	NUL-terminating the result if dstsize is not 0.
	strlcpy() and strlcat() take the full size of the destination buffer and
	guarantee NUL-termination if there is room.
	Note that room for the NUL should be included in dstsize.

PARAMETERS
	

RETURN VALUES
	strlcpy() and strlcat() functions return the total length of the string
	they tried to create.  For strlcpy() that means the length of src.
	For strlcat() that means the initial length of dst plus the length of src.

******PROBLEMS*******
	When a 0 dstsize is passed it must not copy any chars. This must be checked
	separately to avoid entering the while loop because the expression:
		i < dstsize - 1
	Does not work because of the unsignedness of dstsize. This worked:
		while (dstsize != 0 && i < dstsize - 1 && src[i] != '\0')	
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
NAME
	ft_strlcat -- Concatenate string

DESCRIPTION
	strlcat() appends string src to the end of dst.  It will append at most
	dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
	dstsize is 0 or the original dst string was longer than dstsize
	(in practice this should not happen as it means that either dstsize is
	incorrect or that dst is not a proper string).	
	strlcpy() and strlcat() take the full size of the destination buffer and
	guarantee NUL-termination if there is room.
	Note that room for the NUL should be included in dstsize.

PARAMETERS
	

RETURN VALUES
	strlcpy() and strlcat() functions return the total length of the string
	they tried to create.  For strlcpy() that means the length of src.
	For strlcat() that means the initial length of dst plus the length of src.

******PROBLEMS*******
	It NOT be assumed that src is NUL terminated.
	It must NOT be assumed that dst is NUL terminated. First it must be
	checked (within dstsize) that a '\0' is found in dst. If no NUL character
	is found, the function must return inmediately without modifying dst (it 
	would make no sense otherwise because there is no way of knowing where
	is the end of dst).
	If there is a NUL char in dst, then the copy from source can start.
	The copy of chars from src to dst is done while (d < dstsize - 1) but can be
	aborted if (src[s] == '\0') (d starts at the position where '\0' is found
	in dst; s starts at 0). Finally dst is ALWAYS NUL terminated, either at
	position dstsize - 1 (i.e. the case when src doesn't really fit inside dst)
   	or when corresponding given the break of the while loop triggered by the
	if (src[s] == '\0').
	Notice that src might not be NUL terminated. The concatenation would end
	only when !(d < dstsize - 1)
	In every case the return is:
			
	In this case
	there are two possibilities:
		There is room for the whole src to fit + NUL char to fit in dst (always
		according to dstsize and the actual position of the first NUL character
		in dst); or






	When a 0 (or negative) dstsize is passed it must not copy any chars.
	This is a problem
	when evaluating the if condition because size_t is unsigned and must be
	casted with (signed) in order for the condition to behave as expected
	Also, the returned value is NOT the original dst size + ft_strlen(src) but
	dstsize parameter + ft_strlen(src)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_toupper(int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
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


PARAMETERS
	

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
	 character, or NULL if the character does not appear in the string.

******PROBLEMS*******
	
*/
char	*ft_strchr(const char *s, int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
char	*ft_strrchr(const char *s, int c);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
NAME
	memchr -- locate byte in byte string

DESCRIPTION
	The memchr() function locates the first occurrence of c (converted to
	an unsigned char) in string s.


PARAMETERS
	

RETURN VALUES
	The memchr() function returns a pointer to the byte located,
	or NULL if no such byte exists within n bytes.

******PROBLEMS*******
	
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
NAME
	ft_strnstr -- locate a substring in a string
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated
	string needle in the string haystack, where not more than len characters
	are searched.  Characters that appear after a `\0' character
	are not searched.

PARAMETERS
	

RETURN VALUES
    If needle is an empty string, haystack is returned;
	if needle occurs nowhere in haystack, NULL is returned;
    otherwise a pointer to the first character of the first occurrence
	of needle is returned.

******PROBLEMS*******
	
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
int		ft_atoi(const char *str);

/*
NAME
	ft_calloc -- memory allocation
DESCRIPTION
	The calloc() function contiguously allocates enough space for
	count objects that are size bytes of memory each and returns a
	pointer to the allocated memory.  The allocated memory is
	filled with bytes of value zero.

PARAMETERS
	

RETURN VALUES
     If successful, calloc() function return a pointer to allocated memory.
	 If there is an error, they return a NULL pointer and set errno to ENOMEM.

******PROBLEMS*******
	
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

PARAMETERS
	

RETURN VALUES
	The new string

******PROBLEMS*******
	
*/
char	*ft_strdup(const char *s1);

/*
NAME
	ft_substr -- Create new string from original string, start position and len

DESCRIPTION
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.

PARAMETERS
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.

RETURN VALUES
	The substring.
	NULL if the allocation fails

******PROBLEMS*******
	Before starting the copy of the substr, the following must be addressed:
		1 If s = "" or start >= ft_strlen(s), it'd only make sense to return ""
		2 If (start + len > ft_strlen(s)) len must be modified to 
		  len = ft_strlen(s) - start before allocating memory for the substring 

*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
NAME
	ft_split -- Split string according to delimiter char
DESCRIPTION
	Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. 
	The array must end with a NULL pointer.

PARAMETERS
	

RETURN VALUES
	The array of new strings resulting from the split.
	NULL if the allocation fails.

******PROBLEMS*******
	The function is supposed to return a single element array (with NULL value)
   	when argument s is an empty string
*/
char	**ft_split(char const *s, char c);

/*
NAME
	ft_itoa -- Converts int to string representation
DESCRIPTION
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.

PARAMETERS
	

RETURN VALUES
	The string representing the integer.
	NULL if the allocation fails.	

******PROBLEMS*******
	
*/
char	*ft_itoa(int n);

/*
NAME
	ft_strmapi -- Apply a funtion to each char of a string

DESCRIPTION
	Applies the function ’f’ to each character of the
	string ’s’, and passing its index as first argument
	to create a new string (with malloc(3)) resulting
	from successive applications of ’f’.


PARAMETERS
	

RETURN VALUES
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.

******PROBLEMS*******
	
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
NAME
	ft_striteri -- Modify a string applying a function to each of its chars

DESCRIPTION
	Applies the function ’f’ on each character of
	the string passed as argument, passing its index
	as first argument. Each character is passed by
	address to ’f’ to be modified if necessary.


PARAMETERS
	

RETURN VALUES
	None

******PROBLEMS*******
	
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	ft_putchar_fd(char c, int fd);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	ft_putstr_fd(char *s, int fd);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	ft_putendl_fd(char *s, int fd);

/*
NAME
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
*/
void	ft_putnbr_fd(int n, int fd);

/*
NAME
	ft_lstnew -- Create a list element from pointer to its content

DESCRIPTION
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.

PARAMETERS
	content: The content to create the node with.

RETURN VALUES
	The new node

******PROBLEMS*******
	If content == NULL, must return NULL
	If malloc fails, must return NULL
	Int ranges from -2.147.483.648 to 2.147.483.647
*/
t_list	*ft_lstnew(void *content);

/*
NAME
	ft_lstadd_front -- Adds node at the beginning of the list.

DESCRIPTION
	Adds the node ’new’ at the beginning of the list.

PARAMETERS
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.

RETURN VALUES
	None

******PROBLEMS*******
	lst == NULL
	*lst == NULL
	t_list == NULL
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
NAME
	ft_lstsize -- Counts the number of nodes in a list.

DESCRIPTION
	Counts the number of nodes in a list.

PARAMETERS
	lst: The beginning of the list.

RETURN VALUES
	The length of the list

******PROBLEMS*******
	If lst == NULL, return value must be 0
*/
int		ft_lstsize(t_list *lst);

/*
NAME
	ft_lstlast -- Returns the last node of the list.

DESCRIPTION
	Returns the last node of the list.

PARAMETERS
	lst: The beginning of the list.

RETURN VALUES
	Last node of the list

******PROBLEMS*******
	If lst == NULL, return value is NULL
*/
t_list	*ft_lstlast(t_list *lst);

/*
NAME
	ft_lstadd_back --

DESCRIPTION

PARAMETERS
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be	added to the list.

RETURN VALUES
	None

******PROBLEMS*******
	If lst == NULL or new == NULL, nothing must be done
	If *lst == NULL	>>	*lst = new (i.e. lstadd_backing an element to a NULL
	list, creates the list with just that element)
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*
NAME
	ft_lstdelone -- Deletes and frees memory of item list and its content

DESCRIPTION
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.

PARAMETERS
	lst: The node to free.
	del: The address of the function used to delete the content.

RETURN VALUES
	None
******PROBLEMS*******
	CONCEPTUAL: Could break a list because no first item of list nor
	previous item is given. This is the expected behavior
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*
NAME
	ft_lstclear -- Deletes and frees given node and succesors (freeing contents)

DESCRIPTION
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to NULL.

PARAMETERS
	lst: The address of a pointer to a node.
	del: The address of the function used to delete the content of the node.

RETURN VALUES
	None

******PROBLEMS*******
	If lst == NULL, nothing must be done
	*lst == NULL, nothing must be done
	IMPORTANT: del fuction must handle NULL content but must not free the node
	lst MUST be set to NULL by this function
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*
NAME
	ft_lstiter -- Applies function f to the content of each node on list

DESCRIPTION
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.

PARAMETERS
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.

RETURN VALUES
	None

******PROBLEMS*******
	If lst == NULL, return NULL
	CONCEPTUAL: f fuction must handle NULL content?????
				YES! In that case f() must return NULL, also if its malloc call
				fails. f() must return the address of the new content
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
NAME
	ft_lstmap -- Returns new list based on applying f to each nodes content

DESCRIPTION
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.

PARAMETERS
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
	del: The address of the function used to delete
	the content of a node if needed.

RETURN VALUES
	The new list.
	NULL if the allocation fails.

******PROBLEMS*******
	If lst == NULL, NULL must be returned
	CONCEPTUAL: f() fuction must handle NULL content?????
				YES! In that case f() must return NULL, also if its malloc call
				fails. If OK, f() returns a pointer to what would be the content
			   	for the new node
				del() must be able to handle NULL content????
				YES!
	If at some point the funcion fails, the in-construction new list must be
	cleared completely and NULL must be returned
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

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
int		ft_isupper(int c);

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
int		ft_islower(int c);

/*
NAME
	ft_isspace -- White-space character test

DESCRIPTION
	The isspace() function tests for the white-space characters.
	For any locale, this includes the following standard characters:
		'\t'	'\n'	'\v'	'\f'	'\r'	' '

PARAMETERS


RETURN VALUES
	The isspace() function returns zero if the character tests false and
	returns non-zero if the character tests true.

******PROBLEMS*******

*/
int		ft_isspace(int c);

/*
NAME
	ft_issign -- Test for sign char

DESCRIPTION
	Checks character passed as argument looking for a sign char or its abscence

PARAMETERS


RETURN VALUES
	Returns -1 if c is '-'; +1 if c is '+'; 0 if c is neither '+' or '-'

******PROBLEMS*******

*/
int		ft_issign(char c);

/*
NAME
	ft_pow -- Power function

DESCRIPTION
	The pow() functions compute base raised to the power exp.

PARAMETERS


RETURN VALUES
	base^exp

******PROBLEMS*******

*/
int		ft_pow(int base, unsigned int exp);

/*
NAME
	ft_itoa_base -- Version of ft_itoa to support bases up to 16

DESCRIPTION
	...

PARAMETERS
	in_caps -- If hexadecimal, when != 0 uses abcdef instead of ABCDEF

RETURN VALUES
	The size of the string, including memory for '\0' and optionally for
	negative sign

******PROBLEMS*******

*/
char	*ft_itoa_b(int n, unsigned int base, int in_caps);

/*
NAME
	ft_get_sym_table --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
char	*ft_get_sym_table(char *sym_table, unsigned int base, int in_caps);

/*
NAME
	ft_ltoa_b --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
char	*ft_ltoa_b(long n, unsigned int base, int in_caps);

/*
NAME
	ft_ltoa --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
char	*ft_ltoa(long n);

/*
NAME
	ft_print_memory --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
void	*ft_print_memory(void *addr, unsigned int size);

/*
NAME
	ft_ultoa_b --

DESCRIPTION
	

PARAMETERS


RETURN VALUES


******PROBLEMS*******

*/
char	*ft_ultoa_b(unsigned long n, unsigned int base, int in_caps);
#endif
