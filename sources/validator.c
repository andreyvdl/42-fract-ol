#include "../include/fractol.h"

void	validator(t_s_fractal *fractal, char *argv[])
{
	if (name_is_wrong(&(fractal->name), *argv))
		wrong_arg(*argv);
	++argv;
	if (fractal->name == E_MANDELBROT)
		return ;
	else if (fractal->name == E_JULIA)
		validate_julia(argv);
}
