/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:19:26 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 16:19:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Free a pointer if it's not NULL;
 * 
 * @param pointer A pointer to the address of the pointer to be freed;
 */
void	ft_free(void *pointer)
{
	if (pointer)
		free(pointer);
}
