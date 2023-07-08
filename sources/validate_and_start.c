#include "../include/fractol.h"

static void	set_up_fractal(t_s_engine *engine)
{
	if (engine->fractal.name == E_MANDELBROT)
		mandelbrot(engine);
	else if (engine->fractal.name == E_JULIA)
		(void)engine;//julia(&(engine->fractal));
}

void	validate_and_start(char *argv[])
{
	t_s_engine	engine;

	validator(&(engine.fractal), argv);
	init_mlx(&engine);
	if (engine.fractal.name == E_JULIA)
		(void)argv;//extract_args(argv);
	set_up_fractal(&engine);
	mlx_loop(engine.mlx);
	destroy_mlx(&engine);
	exit(0);
}
