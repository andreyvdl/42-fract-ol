/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:34:30 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:34:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	print_options(void)
{
	ft_putstr_fd(ERR_MISSING, STDERR_FILENO);
	ft_putstr_fd(USAGE_STR, STDERR_FILENO);
	exit(CODE_INVARG);
}

void	argc_too_big(void)
{
	ft_putstr_fd(ERR_MANY, STDERR_FILENO);
	ft_putstr_fd(USAGE_STR, STDERR_FILENO);
	exit(CODE_INVARG);
}

void	wrong_arg(char *arg)
{
	ft_printf_fd(STDERR_FILENO, ERR_ARG, arg);
	ft_putstr_fd(USAGE_STR, STDERR_FILENO);
	exit(CODE_INVARG);
}

void	arg_is_null(uint8_t position)
{
	ft_printf_fd(STDERR_FILENO, ERR_ARG_NULL, position);
	ft_putstr_fd(USAGE_STR, STDERR_FILENO);
	exit(CODE_INVARG);
}

void	x_server_fail(void)
{
	ft_putstr_fd(ERR_X_SERVER, STDERR_FILENO);
	exit(CODE_CONREF);
}
