#include "fractol.h"

void	validator(char *argv[])
{
	t_e_name	name;

	if (name_is_wrong(&name, *argv))
		wrong_arg(*argv);
	++argv;
	if (name == E_MANDELBROT)
		return ;
	
}
