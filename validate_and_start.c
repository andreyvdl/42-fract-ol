#include "fractol.h"

void	validate_and_start(char *argv[])
{
	t_s_engine	engine;

	validator(&(engine.fractal), argv);
	//extract_args(argv);
	//engine = init_mlx();
	//set_up_fractal(engine);
	//mlx_loop(engine.mlx);
}
