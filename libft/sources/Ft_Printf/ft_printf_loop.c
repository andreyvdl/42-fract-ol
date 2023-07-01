/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:47:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/23 23:17:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				print_char(char character);
int				print_char_fd(int file_descriptor, char character);
int				print_hexadecimal_lowercase(size_t number);
int				print_hexadecimal_lowercase_fd(int file_descriptor, \
												size_t number);
int				print_hexadecimal_uppercase(size_t number);
int				print_hexadecimal_uppercase_fd(int file_descriptor, \
												size_t number);
int				print_int_fd(int file_descriptor, int number);
int				print_int(int number);
int				print_ptr_fd(int file_descriptor, size_t address);
int				print_ptr(size_t address);
int				print_string(char *string);
int				print_string_fd(int file_descriptor, char *string);
int				print_unsigned_int(__u_int number);
int				print_unsigned_int_fd(int file_descriptor, __u_int number);

static int	print_argument(char byte, va_list arg_list)
{
	if (byte == 'c')
		return (print_char(va_arg(arg_list, int)));
	else if (byte == 's')
		return (print_string(va_arg(arg_list, char *)));
	else if (byte == 'i' || byte == 'd')
		return (print_int(va_arg(arg_list, int)));
	else if (byte == 'u')
		return (print_unsigned_int(va_arg(arg_list, __u_int)));
	else if (byte == 'p')
		return (print_ptr(va_arg(arg_list, size_t)));
	else if (byte == 'x')
		return (print_hexadecimal_lowercase(va_arg(arg_list, size_t)));
	else if (byte == 'X')
		return (print_hexadecimal_uppercase(va_arg(arg_list, size_t)));
	else if (byte == '%')
		return ((int)write(STDOUT_FILENO, "%", 1));
	return ((int)write(STDOUT_FILENO, "%", 1) + \
			(int)write(STDOUT_FILENO, &byte, 1));
}

int	loop_through_string(const char *string, va_list arg_list)
{
	int		bytes_printed;

	bytes_printed = 0;
	while (*string)
	{
		if (*string == '%')
		{
			bytes_printed += print_argument(*(string + 1), arg_list);
			string += 2;
		}
		else
		{
			bytes_printed += (int)write(STDOUT_FILENO, string, 1);
			string++;
		}
	}
	return (bytes_printed);
}

static int	print_argument_fd(int file_descriptor, char byte, va_list arg_list)
{
	if (byte == 'c')
		return (print_char_fd(file_descriptor, va_arg(arg_list, int)));
	else if (byte == 's')
		return (print_string_fd(file_descriptor, va_arg(arg_list, char *)));
	else if (byte == 'i' || byte == 'd')
		return (print_int_fd(file_descriptor, va_arg(arg_list, int)));
	else if (byte == 'u')
		return (print_unsigned_int_fd(file_descriptor, \
										va_arg(arg_list, __u_int)));
	else if (byte == 'p')
		return (print_ptr_fd(file_descriptor, va_arg(arg_list, size_t)));
	else if (byte == 'x')
		return (print_hexadecimal_lowercase_fd(file_descriptor, \
												va_arg(arg_list, size_t)));
	else if (byte == 'X')
		return (print_hexadecimal_uppercase_fd(file_descriptor, \
												va_arg(arg_list, size_t)));
	else if (byte == '%')
		return ((int)write(file_descriptor, "%", 1));
	else
		return ((int)write(file_descriptor, "%", 1) + \
		(int)write(file_descriptor, &byte, 1));
}

int	loop_through_string_fd(int file_descriptor, const char *string, \
							va_list arg_list)
{
	int		bytes_printed;

	bytes_printed = 0;
	while (*string)
	{
		if (*string == '%')
		{
			bytes_printed += print_argument_fd(file_descriptor, \
												*(string + 1), arg_list);
			string += 2;
		}
		else
		{
			bytes_printed += (int)write(file_descriptor, string, 1);
			string++;
		}
	}
	return (bytes_printed);
}
