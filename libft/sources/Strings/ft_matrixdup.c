/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:44:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_matrix_size(char **matrix)
{
	size_t	size;

	size = 0;
	while (*(matrix + size))
		size++;
	return (size);
}

static size_t	get_string_size(char *string)
{
	size_t	size;

	size = 0;
	while (*(string + size))
		size++;
	return (size);
}

static void	malloc_and_duplicate(char *matrix, char **copy, size_t line)
{
	*(copy + line) = (char *)malloc((get_string_size(matrix) + 1) * \
								sizeof(char));
	if (*(copy + line) == NIL)
		return ;
	while (*matrix)
	{
		**(copy + line) = *matrix++;
		(*(copy + line))++;
	}
	**(copy + line) = '\0';
}

static void	clear_matrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(matrix);
}

/**
 * @brief Duplicates a matrix of strings;
 * 
 * @param matrix A pointer to the matrix to be duplicated;
 * @return A copy of the matrix (char **);
 */
char	**ft_matrixdup(char **matrix)
{
	char	**copy;
	size_t	line;

	if (matrix == NIL || *matrix == NIL)
		return (NIL);
	copy = (char **)malloc((get_matrix_size(matrix) + 1) * sizeof(char *));
	if (copy == NIL)
		return (NIL);
	line = 0;
	while (*matrix)
	{
		malloc_and_duplicate(*matrix, copy, line);
		if (*(copy + line) == NIL)
		{
			clear_matrix(copy);
			return (NIL);
		}
		line++;
		matrix++;
	}
	*(copy + line) = NIL;
	return (copy);
}
