/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*create_new_node(char *string)
{
	t_list	*new_node;

	if (string == NIL)
		return (NIL);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NIL)
		return (NIL);
	new_node->content = string;
	new_node->next = NIL;
	return (new_node);
}

static void	add_to_the_end(t_list **list, t_list *new_node)
{
	t_list	*temporary;

	if (new_node == NIL)
		return ;
	else if (*list == NIL)
	{
		*list = new_node;
		return ;
	}
	temporary = *list;
	while (temporary->next)
		temporary = temporary->next;
	temporary->next = new_node;
}

/**
 * @brief Creates a new list with the strings passed as parameters;
 * 
 * @param size The size of the array of strings;
 * @param strs A pointer to an array of pointers to strings;
 * @return A pointer to the first node of the list (t_list *);
 */
t_list	*ft_list_push_strs(size_t size, char **strs)
{
	t_list	*list;

	if (strs == NIL || *strs == NIL)
		return (NIL);
	list = NIL;
	while (size)
	{
		add_to_the_end(&list, create_new_node(strs[size]));
		size--;
	}
	add_to_the_end(&list, create_new_node(strs[size]));
	return (list);
}
