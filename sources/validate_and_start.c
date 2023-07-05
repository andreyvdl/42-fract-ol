#include "../include/fractol.h"

void	validate_and_start(char *argv[])
{
	t_s_engine	engine;

	validator(&(engine.fractal), argv);
	init_mlx(&engine);
	//extract_args(argv);
	//set_up_fractal(engine);
	//mlx_loop(engine.mlx);
}
