#include "../../include/fractol.h"

void	change_mode(t_s_engine *engine)
{
	if (engine->fractal.mode == E_COLOR)
	{
		engine->fractal.mode = E_GRADIENT;
		ft_putendl("Gradient mode");
	}
	else
	{
		engine->fractal.mode = E_COLOR;
		ft_putendl("Color mode");
	}
	mlx_clear_window(engine->mlx, engine->win);
	select_to_draw(engine);
}
