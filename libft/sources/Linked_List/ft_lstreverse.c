/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:33:51 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Reverses the order of a list; If the list is NULL, nothing happens;
 * 
 * @param begin_list A pointer to the address of the first node of the list;
 */
void	ft_lstreverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	if (begin_list == NIL || *begin_list == NIL)
		return ;
	previous = NIL;
	current = *begin_list;
	while (current != NIL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
