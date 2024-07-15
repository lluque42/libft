/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:56:57 by lluque            #+#    #+#             */
/*   Updated: 2024/07/16 00:44:22 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_dlclst.h
 * Doubly linked circular list implementation. Part of libft library.  
 * A dlclst has a head which points to the node that is to be interpreted as the
 * begining of the list or its first element. In the same way, the list alsohas
 * a last element which will be the node pointed to by the 'prev' field of the
 * head node.  
 * In a dlclst list with just one element, that element will point to itself.
 * That is, the only node will be the first and the last at the same time.  
 * In this sense, due to the circular nature of the dlclst list, NO check is
 * performed against the size of the list while operating on their elements and
 * traversing the list. A value for position or steps from one node to another
 * that could cause an overflow of the head of the list is allowed and will be
 * interpreted consistently with the circular nature of the list.
*/

#ifndef FT_DLCLST_H
# define FT_DLCLST_H

/**
 * @struct s_dlclst
 * @brief Base for typedef <b>t_dlclst</b> for a doubly linked circular list
 * node.
 * @details This type is used as a node for a doubly linked (two-way) dynamic
 * circular list.  
 * Any node could serve  as a list for itself (i.e. as the head of a list).
 * @var s_dlclst::content
 * Pointer to void to allow caller to use arbitrary type.
 * @var s_dlclst::prev
 * Pointer to previous node of the list. Will point to itself if it is the only
 * node in the list.
 * @var s_dlclst::next
 * Pointer to next node of the list. Will point to itself if it is the only
 * node in the list.
*/
typedef struct s_dlclst
{
	void			*content;
	struct s_dlclst	*prev;
	struct s_dlclst	*next;
}				t_dlclst;
/**
 * @typedef t_dlclst
 * Based on the @link s_dlclst @endlink struct.
 */

/**
 * @brief <b>ft_dlclst_new</b> -- Creates a list element from pointer to
 * its content.
 *
 * @details Allocates (with malloc()) and returns a new node.  
 * The member variable ’content’ is initialized with the value of the parameter
 * ’content’. The variables 'next' and 'prev' are initialized to NULL.
 * 
 * @param [in] content - The pointer to the content to create the node with.
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
t_dlclst	*ft_dlclst_new(void *content);

/**
 * @brief <b>ft_dlclst_insfront</b> -- Inserts node at the beginning of
 * the list.
 *
 * @details Inserts the node ’new’ at the beginning of the list. If *lst == NULL
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
void		ft_dlclst_insfront(t_dlclst **lst, t_dlclst *new);

/**
 * @brief <b>ft_dlclst_insback</b> -- Inserts node at the end of
 * the list.
 *
 * @details Inserts the node ’new’ at the end of the list. If *lst == NULL
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
void		ft_dlclst_insback(t_dlclst **lst, t_dlclst *new);

/**
 * @brief <b>ft_dlclst_inspos</b> -- Inserts node at given position.
 *
 * @details Inserts the node ’new’ at given position. If *lst == NULL
 * the new node becomes the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first node of a list.
 *
 * @param [in] new - A pointer to the node to be added to the list.
 *
 * @param [in] pos - Positive value representing the position the new node  will
 * have inside the list (always in the next direction, first node has 0 pos).  
 * A zero value produces the same result as ft_dlclst_insertfront().  
 *
 * @warning NO check is performed for NULL pointers passed as arguments. In
 * such cases, CRASHING is guaranteed.  
 * NO check is performed for element position as relative to the size
 * of the list. A value for position or steps that could cause an overflow of
 * the head of the list is allowed and will be interpreted consistently with the
 * circular nature of the list.
 *
 * @remark Implementation notes:  
 * Don't check for valid pointers.
*/
void		ft_dlclst_inspos(t_dlclst **lst, t_dlclst *new, unsigned int pos);

/**
 * @brief <b>ft_dlclst_size</b> -- Counts the number of nodes in a list.
 *
 * @details Counts the number of nodes in a list.
 * 
 * @param [in] lst - A pointer to the first element of the list.
 *
 * @return The length of the list.  
 * If lst == NULL a 0 value is returned.
*/
int			ft_dlclst_size(t_dlclst *lst);

/**
 * @brief <b>ft_dlclst_last</b> -- Returns the last node of the list.
 *
 * @details Returns the last node of the list.
 * 
 * @param [in] lst - A pointer to the first node of the list.
 *
 * @return A pointer to the last node of the list.  
 * Returns NULL if lst == NULL. 
*/
t_dlclst	*ft_dlclst_last(t_dlclst *lst);

/**
 * @brief <b>ft_dlclst_remfront</b> -- Removes the first node of the list and
 * frees memory of the list item and its content.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list and frees the memory of the first node content using the
 * ’del’ function provided by the caller. Then frees the node memory.  
 * The memory of 'next' and 'prev' nodes of the deleted first node are not
 * freed. The pointers of those nodes are updated in order to maintain the
 * consistency of the circular list.  
 * The pointer to lst is updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] lst - The address of the pointer to the first node of
 * the list.
 *
 * @param [in] del - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
*/
void		ft_dlclst_remfront(t_dlclst **lst, void (*del)(void *));

/**
 * @brief <b>ft_dlclst_remback</b> -- Removes the last node of the list and
 * frees memory of the list item and its content.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list and frees the memory of the last node content using the
 * ’del’ function provided by the caller. Then frees the node memory.  
 * The memory of 'next' and 'prev' nodes of the deleted first node are not
 * freed. The pointers of those nodes are updated in order to maintain the
 * consistency of the circular list.  
 * The pointer to lst might be updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] lst - The address of the pointer to the first node of
 * the list.
 *
 * @param [in] del - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer.
 *
 * @warning EXTERNAL FUNCTION USED: free().  
*/
void		ft_dlclst_remback(t_dlclst **lst, void (*del)(void *));

/**
 * @brief <b>ft_dlclst_rempos</b> -- Removes the node of the list at given
 * position and frees memory of the list item and its content.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list and frees the memory of the referred node content using the
 * ’del’ function provided by the caller. Then frees the node memory.  
 * The memory of 'next' and 'prev' nodes of the deleted first node are not
 * freed. The pointers of those nodes are updated in order to maintain the
 * consistency of the circular list.  
 * The pointer to lst might be updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] l - The address of the pointer to the first node of
 * the list.
 *
 * @param [in] d - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer.
 *
 * @param [in] pos - Positive value representing the position in the list of 
 * the node to be removed (always in the next direction, first node has 0 pos).  
 * A zero value produces the same result as ft_dlclst_remfront().
 *
 * @warning EXTERNAL FUNCTION USED: free().  
 * NO check is performed for element position as relative to the size
 * of the list. A value for position or steps that could cause an overflow of
 * the head of the list is allowed and will be interpreted consistently with the
 * circular nature of the list.
*/
void		ft_dlclst_rempos(t_dlclst **l, void (*d)(void *), int unsigned pos);

/**
 * @brief <b>ft_dlclst_clear</b> -- Deletes and frees given node and succesors.
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
*/
void		ft_dlclst_clear(t_dlclst **lst, void (*del)(void *));

/**
 * @brief <b>ft_dlclst_iter</b> -- Applies provided function f to the content
 * of each node on list.
 *
 * @details Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node.
 * 
 * @param [in] lst - The address of a pointer to a node. If NULL nothing is
 * done.
 *
 * @param [in] f - The address of the function that shall be used apply on every
 * node's content while traversing the whole list. This function must be capable
 * of handling a NULL content pointer.
 *
 * @warning NO check is performed for NULL pointers passed as arguments. In
 * such cases, CRASHING is guaranteed.
*/
void		ft_dlclst_iter(t_dlclst *lst, void (*f)(void *));

/**
 * @brief <b>ft_dlclst_map</b> -- Returns new list based on applying f to each
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
 * @param [in] l - The address of a pointer to a node. If NULL nothing is done
 * and a NULL pointer is returned.
 *
 * @param [in] f - The address of the function that shall be applied on every
 * node's content while traversing the original list to return a pointer to the
 * new content for every node of the new list. This function must be capable of
 * handling a NULL content pointer. This function must allocate memory for the
 * generated new contents. This function must return NULL if error.
 *
 * @param [in] d - The address of the function that shall be used to properly
 * free only the content of the node. This function must be capable of handling
 * a NULL content pointer. This function is used if an error occurs while
 * creating the new list.
 *
 * @return The new list.  
 * NULL if error occurs.
 *
 * @warning EXTERNAL FUNCTION USED: malloc(), free().  
*/
t_dlclst	*ft_dlclst_map(t_dlclst *l, void *(*f)(void *), void (*d)(void *));

/**
 * @brief <b>ft_dlclst_search</b> -- Search content inside the list.
 *
 * @details Iterates the list ’lst’ and applies the function ’cmp’  to compare
 * the content of each node with the content passed as argument. The first time
 * a match is detected (in the next direction), the position of the element
 * is returned.
 * 
 * @param [in] l - The pointer to a list. If NULL, -1 is returned.
 *
 * @param [in] cmp - The address of the function that shall be applied on every
 * node's content while traversing the original list to compare it against the
 * content 'co'. This function returns a non-zero value if there is a match.
 * This function must be capable of  handling a NULL content pointer.
 *
 * @param [in] co - The address of a content to be compared against each node's
 * content.
 *
 * @return The position of the first node (in the next direction) which content
 * matches the content passed as an argument.  
 * A -1 is returned if there is no match.
*/
int			ft_dlclst_search(t_dlclst *l, int (*cmp)(void *, void *), void *co);

/**
 * @brief <b>ft_dlclst_rotatenext</b> -- Shifts the head of the list in the
 * 'next' direction.
 *
 * @details Moves the pointer that points to the head/front of the
 * list 'n' steps in the 'next' direction, thus making the element in the 
 * n-th position the new head/front of the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first node of a list.
 *
 * @param [in] n - The steps to move the head of the list.
 *
 * @warning NO check is performed for element position as relative to the size
 * of the list. A value for position or steps that could cause an overflow of
 * the head of the list is allowed and will be interpreted consistently with the
 * circular nature of the list.
*/
void		ft_dlclst_rotatenext(t_dlclst **lst, unsigned int n);

/**
 * @brief <b>ft_dlclst_rotateprev</b> -- Shifts the head of the list in the
 * 'prev' direction.
 *
 * @details Moves the pointer that points to the head/front of the
 * list 'n' steps in the 'prev' direction, thus making the element in the 
 * (size -n)-th position the new head/front of the list.
 * 
 * @param [in,out] lst - The address of a pointer to the first node of a list.
 *
 * @param [in] n - The steps to move the head of the list.
 *
 * @warning NO check is performed for element position as relative to the size
 * of the list. A value for position or steps that could cause an overflow of
 * the head of the list is allowed and will be interpreted consistently with the
 * circular nature of the list.
*/
void		ft_dlclst_rotateprev(t_dlclst **lst, unsigned int n);

/**
 * @brief <b>ft_dlclst_swapfront</b> -- Swaps the first and second elements of
 * the list.
 *
 * @details Swaps the first and second elements of the list. The head of the
 * list changes accordingly.
 *
 * @param [in,out] lst - The address of a pointer to the first node of a list.
*/
void		ft_dlclst_swapfront(t_dlclst **lst);

/**
 * @brief <b>ft_dlclst_swapback</b> -- Swaps the last and next to last elements
 * of the list.
 *
 * @details Swaps the last and next to last elements of the list. The head of
 * the list may change accordingly (i.e. in a list with just two elements).
 *
 * @param [in,out] lst - The address of a pointer to the first node of a list.
*/
void		ft_dlclst_swapback(t_dlclst **lst);

/**
 * @brief <b>ft_dlclst_extractfront</b> -- Removes the first node of the list
 * and returns it.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list, removes it from the list and returns it. The pointers of the
 * remaining nodes of the list are updated in orderr to maintain the
 * consistency of the circular list.  
 * The pointer to lst is updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] lst - The address of the pointer to the first node of
 * the list.
 *
 * @return The extracted node.
 */
t_dlclst	*ft_dlclst_extractfront(t_dlclst **lst);

/**
 * @brief <b>ft_dlclst_extractback</b> -- Removes the last node of the list and
 * returns it.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list, removes it from the list and returns it. The pointers of the     
 * remaining nodes of the list are updated in order to maintain the
 * consistency of the circular list.  
 * The pointer to lst might be updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] lst - The address of the pointer to the first node of
 * the list.
 *
 * @return The extracted node.
*/
t_dlclst	*ft_dlclst_extractback(t_dlclst **lst);

/**
 * @brief <b>ft_dlclst_extractpos</b> -- Removes the node of the list at given
 * position and returns it.
 *
 * @details Takes as a parameter the address of the pointer to the first node
 * of the list, removes the node that occupies the given position from the list
 * and returns it. The pointers of the remaining nodes of the list are updated
 * in order to maintain the consistency of the circular list.  
 * The pointer to lst might be updated to represent the new first element of the
 * list. It will be NULL if the removed node was the only element in the list.
 * 
 * @param [in, out] lst - The address of the pointer to the first node of
 * the list.
 *
 * @param [in] pos - Positive value representing the position in the list of
 * the node to be extracted (always in the next direction, first node has a
 * position of 0).  
 * A zero value produces the same result as ft_dlclst_extractfront().
 *
 * @return The extracted node.
 * @warning NO check is performed for element position as relative to the size
 * of the list. A value for position or steps that could cause an overflow of
 * the head of the list is allowed and will be interpreted consistently with the
 * circular nature of the list.
*/
t_dlclst	*ft_dlclst_extractpos(t_dlclst **lst, unsigned int pos);

#endif
