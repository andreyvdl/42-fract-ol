#include "../../include/fractol.h"

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

void	validate_julia(t_s_fractal *fractal, char *argv[])
{
	double	temp;

	if (*argv == NIL)
		arg_is_null(1);
	julia_nbr_is_valid(*argv);
	temp = ft_atof(*argv++);
	if (temp > 2.0 || temp < -2.0)
		wrong_arg(*(argv - 1));
	fractal->julia_cx = temp;
	if (*argv == NIL)
		arg_is_null(2);
	julia_nbr_is_valid(*argv);
	temp = ft_atof(*argv);
	if (temp > 2.0 || temp < -2.0)
		wrong_arg(*argv);
	fractal->julia_cy = temp;
}
