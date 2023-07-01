/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	loop_through_string(const char *string, va_list arg_list);

/**
 * @brief My version of the printf function;
 * 			It accepts the following flags: cspdiuxX%;
 * 			Any invalid flag will print % plus the invalid flag;
 * @attention If too many characters are written it can cause an overflow;
 * 
 * @param string A pointer to the string to be printed;
 * @param ... The variables and/or functions return to be printed;
 * @return The total of characters printed (int); Or -1 if the string is NULL;
 */
int	ft_printf(const char *string, ...)
{
	int		bytes_printed;
	va_list	arg_list;

	if (string == NIL)
		return (-1);
	va_start(arg_list, string);
	bytes_printed = loop_through_string(string, arg_list);
	va_end(arg_list);
	return (bytes_printed);
}
