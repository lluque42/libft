/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:41:10 by lluque            #+#    #+#             */
/*   Updated: 2023/09/26 22:03:52 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

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
	When a 0 dstsize is passed it must not copy any chars. This is a problem
	when evaluating the if condition because size_t is unsigned and must be
	casted with (signed) in order for the condition to behave as expected
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
	When a 0 dstsize is passed it must not copy any chars. This is a problem
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
	--

DESCRIPTION
	


PARAMETERS
	

RETURN VALUES
	

******PROBLEMS*******
	
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
	If content == NULL 
	If malloc fails	
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
	lst == NULL
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
	lst == NULL
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
	lst == NULL
	*lst == NULL	>>	resolves ft_lstlast
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
	previous item is given
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
	lst == NULL
	*lst == NULL
	CONCEPTUAL: del fuction must handle NULL content?????
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
	lst == NULL
	CONCEPTUAL: f fuction must handle NULL content?????
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
	lst == NULL
	CONCEPTUAL: f and del fuctions must handle NULL content?????
				f must return what would be the content of the new node?????
					THIS WAS ASSUMED (SO FAR)
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
NAME
	--

DESCRIPTION
	

PARAMETERS
	

RETURN VALUES
	
******PROBLEMS*******
	c not ASCII
*/
int		ft_isspace(int c);

/*
NAME
	--

DESCRIPTION
	

PARAMETERS
	

RETURN VALUES
	
******PROBLEMS*******
	c not ASCII
*/
int		ft_isupper(int c);

/*
NAME
	--

DESCRIPTION
	

PARAMETERS
	

RETURN VALUES
	
******PROBLEMS*******
	c not ASCII
*/
int		ft_islower(int c);

/*
NAME
	--

DESCRIPTION
	

PARAMETERS
	

RETURN VALUES
	
******PROBLEMS*******
	c not ASCII
*/
int		ft_issign(char c);

/*
NAME
	--

DESCRIPTION
	

PARAMETERS
	

RETURN VALUES
	
	
******PROBLEMS*******
	exp < 0
	result > maximum integer
*/
int		ft_exp(int base, int exp);

/*
NAME
	ft_strcount -- Counts ocurrences of char in string

DESCRIPTION
	Using ft_strchr...

PARAMETERS
	

RETURN VALUES
	The number of occurences

******PROBLEMS*******
	
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

PARAMETERS
	

RETURN VALUES
	The new string

******PROBLEMS*******
	
*/
char	*ft_strextract(char *s, size_t pos);

/*
NAME
	ft_free_str_array -- Frees allocated memory for array of strings

DESCRIPTION
	Takes a pointer to a pointer of char (array of strings) and the amount
	of elements of the array with memory allocated. This function frees the
	number of elements indicated (starting at element 0) and finally also
	frees the **char

PARAMETERS
	

RETURN VALUES
	None

******PROBLEMS*******
	
*/
void	ft_free_str_array(char **str_array, int allocated_strings);

/*
NAME
	ft_conv_less_sig_dig -- To use for converting numbers to another base

DESCRIPTION
	Takes a pointer to an integer...

PARAMETERS
	

RETURN VALUES


******PROBLEMS*******
	
*/
char	ft_conv_less_sig_dig(int *nbr, int base, char *sym_table);

/*
NAME
	ft_get_sym_table_base --

DESCRIPTION
	Takes a pointer to an integer...

PARAMETERS
	

RETURN VALUES


******PROBLEMS*******
	
*/
char	*ft_get_sym_table_base(unsigned int base);

/*
NAME
	ft_size_str_for_dec -- Obtain a size for a string in which a int fits

DESCRIPTION
	...

PARAMETERS
	

RETURN VALUES
	The size of the string, including memory for '\0' and optionally for 
	negative sign

******PROBLEMS*******
	
*/
int		ft_size_str_for_dec(int dec_nbr, int base_for_string, int include_sign);

/*
NAME
	ft_itoa_base -- 

DESCRIPTION
	...

PARAMETERS
	

RETURN VALUES
	The size of the string, including memory for '\0' and optionally for 
	negative sign

******PROBLEMS*******
	
*/
char	*ft_itoa_b(int n, unsigned int base);

//char    *ft_ltoa(long n);
#endif
