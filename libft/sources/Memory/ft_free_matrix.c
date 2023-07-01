/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:17:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 16:19:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Free a matrix if it's not NULL;
 * 
 * @param matrix A pointer to the address of the matrix to be freed;
 */
void	ft_free_matrix(void **matrix)
{
	char	**temp;

	if (matrix)
	{
		temp = (char **)matrix;
		while (*temp)
			free(*temp++);
		free(matrix);
	}
}
