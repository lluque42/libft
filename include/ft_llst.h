/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:57 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 00:45:06 by lluque           ###   ########.fr       */
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
 * @typedef t_list
 * Based on the @link s_list @endlink struct.
 */

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
 * Returns NULL if malloc() fails.
 *
 * @warning EXTERNAL FUNCTION USED: malloc().  
 * 
 * @remark Implementation notes:  
 * Argument content is NOT checked for NULL, a node with NULL content is
 * returned.  
 * If malloc fails, must return NULL.
 *
*/
t_list	*ft_lstnew(void *content);

/**
 * @brief <b>ft_lstadd_front</b> -- Adds node at the beginning of the list.
 *
 * @details Adds the node ’new’ at the beginning of the list. If *lst == NULL
 * the new node becomes the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first node of a list.
 *
 * @param [in] new - A pointer to the node to be added to the list.
 *
 * @warning NO check is performed for NULL pointers passed as arguments. In
 * such cases, CRASHING is guaranteed.
 *
 * @remark Implementation notes:  
 * Don't check for valid pointers.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief <b>ft_lstsize</b> -- Counts the number of nodes in a list.
 *
 * @details Counts the number of nodes in a list.
 * 
 * @param [in] lst - A pointer to the first element of the list.
 *
 * @return The length of the list.  
 * If lst == NULL a 0 value is returned.
*/
int		ft_lstsize(t_list *lst);

/**
 * @brief <b>ft_lstlast</b> -- Returns the last node of the list.
 *
 * @details Returns the last node of the list.
 * 
 * @param [in] lst - A pointer to the first node of the list.
 *
 * @return A pointer to the last node of the list.  
 * Returns NULL if lst == NULL. 
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief <b>ft_lstadd_back</b> -- Adds node at the end of the list.
 *
 * @details Adds the node ’new’ at the end of the list. If *lst == NULL
 * the new node becomes the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first node of a list.
 *
 * @param [in] new - A pointer to the node to be added to the list.
 *
 * @warning NO check is performed for NULL pointers passed as arguments. In
 * such cases, CRASHING is guaranteed. TODO. This is not true, check with paco..
 *
 * @remark Implementation notes:  
 * Don't check for valid pointers.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief <b>ft_lstdelone</b> -- Deletes and frees memory of item list and its 
 * content.
 *
 * @details Takes as a parameter a node and frees the memory of the node’s
 * content using the function ’del’ given as a parameter and free the node.  
 * The memory of ’next’ must not be freed. This function may break a list
 * if used without caution.
 * 
 * @param [in] lst - A pointer to the node to be freed.
 *
 * @param [in] del - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
 * The caller should set lst to NULL after freeing memory with this
 * funcion.  
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief <b>ft_lstclear</b> -- Deletes and frees given node and succesors.
 * (freeing contents).
 *
 * @details Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free().  
 * Finally, the pointer to the node is set to NULL.
 * 
 * @param [in,out] lst- The address of a pointer to a node. If NULL, nothing is
 * done. Is set to NULL by this function.
 *
 * @param [in] del - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
 *
 * @remark Implementation notes:  
 * TODO (Paco-check this, it should crash).  
 * If lst == NULL, nothing must be done.  
 * TODO (this makes sense, empty list).  
 * If *lst == NULL, nothing must be done.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief <b>ft_lstiter</b> -- Applies provided function f to the content
 * of each node on list.
 *
 * @details Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node.
 * 
 * @param lst - The address of a pointer to a node. If NULL nothing is done.
 *
 * @param f - The address of the function that shall be applied on every
 * node's content while traversing the whole list. This function must be capable
 * of handling a NULL content pointer.
 *
 * @warning NO check is performed for NULL pointers passed as arguments. In
 * such cases, CRASHING is guaranteed.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief <b>ft_lstmap</b> -- Returns new list based on applying f to each
 * nodes content.
 *
 * @details Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node. Creates a new list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to delete the content of a node
 * if needed. If at some point the funcion fails, the in-construction new list
 * must is cleared completely and NULL pointer is returned.

 * If an error occurs while creating the new list, every memory is
 * freed and a NULL is returned.
 * 
 * @param [in] lst - The address of a pointer to a node. If NULL nothing is done
 * and a NULL pointer is returned.
 *
 * @param [in] f - The address of the function that shall be applied on every
 * node's content while traversing the original list to return a pointer to the
 * new content for every node of the new list. This function must be capable of
 * handling a NULL content pointer. This function must allocate memory for the
 * generated new contents. This function must return NULL if error.
 *
 * @param [in] del - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer. This function is used if an error occurs while
 * creating the new list.
 *
 * @return The new list.  
 * NULL if error occurs.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), free().  
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
