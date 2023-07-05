#include "../include/fractol.h"

bool	name_is_wrong(t_e_name *name, char *arg)
{
	char	*temp;

	temp = arg;
	while (*temp != '\0')
	{
		*temp = ft_toupper(*temp);
		++temp;
	}
	if (ft_strncmp(arg, MANDELBROT_STR, sizeof(MANDELBROT_STR)) == 0)
	{
		*name = E_MANDELBROT;
		return (false);
	}
	else if (ft_strncmp(arg, JULIA_STR, sizeof(JULIA_STR)) == 0)
	{
		*name = E_JULIA;
		return (false);
	}
	return (true);
}
