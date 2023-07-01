/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:18:26 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*create_new_node(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NIL)
		return (NIL);
	new_node->content = content;
	new_node->next = NIL;
	return (new_node);
}

static void	clear_list(t_list **list, void (*delete_function)(void *))
{
	t_list	*temporary;

	if (list == NIL || *list == NIL)
		return ;
	while (*list != NIL)
	{
		temporary = (*list)->next;
		delete_function((*list)->content);
		free(*list);
		*list = temporary;
	}
}

static void	add_node_to_new_list(t_list **new_list, t_list *new_node)
{
	t_list	*temporary;

	if (*new_list == NIL)
	{
		*new_list = new_node;
		return ;
	}
	temporary = *new_list;
	while (temporary->next != NIL)
		temporary = temporary->next;
	temporary->next = new_node;
}

/**
 * @brief Creates a copy of the list, applying the function f to each node
 * 			content; If allocation fails, the function returns NULL and deletes
 * 			the new list;
 * 
 * @param lst A pointer to the first node of the list;
 * @param f A pointer to the function that applies the fix to the node content;
 * @param del A pointer to the function that deletes the node content;
 * @return A pointer to the first node of the new list (t_list *);
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (lst == NIL)
		return (NIL);
	new_list = NIL;
	while (lst)
	{
		new_node = create_new_node(f(lst->content));
		if (new_node == NIL)
		{
			clear_list(&new_list, del);
			return (NIL);
		}
		add_node_to_new_list(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
