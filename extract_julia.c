#include "fractol.h"

static void	julia_nbr_is_valid(char *arg)
{
	char	*temp;

	temp = arg;
	while (*temp == ' ' || *temp == '\t' || *temp == '\n' || \
	*temp == '\v' || *temp == '\f' || *temp == '\r')
		++temp;
	if (*temp == '-' || *temp == '+')
		++temp;
	while (ft_isdigit(*temp))
		++temp;
	if (temp != arg && (*(temp - 1) < '0' || *(temp - 1) > '9'))
		wrong_arg(arg);
	else if (temp == arg && *temp == '.')
		wrong_arg(arg);
	if (*temp == '.')
		++temp;
	while (ft_isdigit(*temp))
		++temp;
	while (*temp == ' ' || *temp == '\t' || *temp == '\n' || \
	*temp == '\v' || *temp == '\f' || *temp == '\r')
		++temp;
	if (*temp != '\0')
		wrong_arg(arg);
}

void	extract_julia(t_s_fractal *fractal, char *argv[])
{
	if (*argv == NIL)
		arg_is_null(1);
	julia_nbr_is_valid(*argv);
	fractal->x_real = ft_atof(*argv++);
	if (fractal->x_real > 2.0 || fractal->x_real < -2.0)
		wrong_arg(*(argv - 1));
	if (*argv == NIL)
		arg_is_null(2);
	julia_nbr_is_valid(*argv);
	fractal->x_imag = ft_atof(*argv);
	if (fractal->x_imag > 2.0 || fractal->x_imag < -2.0)
		wrong_arg(*argv);
}
