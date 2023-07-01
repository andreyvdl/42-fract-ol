/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:45:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Find a node in the list that matches the data_ref;
 * 
 * @param begin_list A pointer to the begin of the list;
 * @param data_ref The data to be compared;
 * @param cmp The function to compare the data;
 * @return A pointer to the node (t_list *) that matches the data_ref; If isn't
 * 			possible, then return NULL;
 */
t_list	*ft_list_find(t_list *begin_list, void *data_ref, \
						int (*cmp)(void *, void *))
{
	if (begin_list == NIL || data_ref == NIL || cmp == NIL)
		return (NIL);
	while (begin_list)
	{
		if (cmp(begin_list->content, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NIL);
}
