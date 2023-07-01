/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:33 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*get_last_node(t_list *list)
{
	while (list->next != NIL)
		list = list->next;
	return (list);
}

/**
 * @brief Add a new node at the end of the list; If the list is NULL, the new
 * 			node will be the first node; If the new node is NULL, nothing will
 * 			happen;
 * 
 * @param lst The address of a pointer to the first link of a list;
 * @param new The pointer to the new node to be added to the list;
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NIL)
		return ;
	else if (*lst == NIL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = get_last_node(last);
	last->next = new;
}
