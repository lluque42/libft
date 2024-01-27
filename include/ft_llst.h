/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:57 by lluque            #+#    #+#             */
/*   Updated: 2024/01/25 02:02:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_llst.h
  Linked list implementation. Part of libft library.
*/

#ifndef FT_LLST_H
# define FT_LLST_H

/**
 * @struct s_list
 * @brief Base for typedef <b>t_list</b> for a linked list node.
 * @details This type is used as a node for a one-way dynamic linked list.
 * Any node could serve  as a list for itself (i.e. as the beginning of a list).
 * @var s_list::content
 * Pointer to void to allow caller to use arbitrary type.
 * @var s_list::next
 * Pointer to next node of the list. NULL if last node.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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
