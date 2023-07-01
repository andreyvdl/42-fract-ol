/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:51:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_realloc_free(char **ptr)
{
	size_t	i;
	size_t	j;
	char	*new_ptr;

	i = 0;
	if (!ptr)
		return (NIL);
	while ((*ptr)[i] != '\n' && (*ptr)[i] != 0)
		i++;
	j = ft_strlen(*ptr);
	if (j - i <= 0)
	{
		new_ptr = ft_calloc(sizeof(char), 1);
		free(*ptr);
		return ((void *)new_ptr);
	}
	else
		new_ptr = ft_calloc(sizeof(char), j - i + 1);
	i++;
	j = 0;
	while ((*ptr)[i] != 0)
		new_ptr[j++] = (*ptr)[i++];
	free(*ptr);
	*ptr = NIL;
	return ((void *)new_ptr);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	sz;

	if (s1 == NIL || s2 == NIL)
		return (NIL);
	sz = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * sz);
	if (str == NIL)
		return (NIL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	free(s1);
	s1 = NIL;
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
