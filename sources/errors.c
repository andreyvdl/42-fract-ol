#include "../include/fractol.h"

void	print_options(void)
{
	ft_printf_fd(STDERR_FILENO, ERR_MISSING);
	ft_printf_fd(STDERR_FILENO, USAGE_STR);
	exit(CODE_INVARG);
}

void	argc_too_big(void)
{
	ft_printf_fd(STDERR_FILENO, ERR_MANY);
	ft_printf_fd(STDERR_FILENO, USAGE_STR);
	exit(CODE_INVARG);
}

void	wrong_arg(char *arg)
{
	ft_printf_fd(STDERR_FILENO, ERR_ARG, arg);
	ft_printf_fd(STDERR_FILENO, USAGE_STR);
	exit(CODE_INVARG);
}

void	arg_is_null(uint8_t position)
{
	ft_printf_fd(STDERR_FILENO, ERR_ARG_NULL, position);
	ft_printf_fd(STDERR_FILENO, USAGE_STR);
	exit(CODE_INVARG);
}

void	x_server_fail(void)
{
	ft_printf_fd(STDERR_FILENO, ERR_X_SERVER);
	exit(CODE_CONREF);
}