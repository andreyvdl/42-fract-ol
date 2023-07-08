#include "../../include/fractol.h"

void	destroy_mlx(t_s_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->img);
	mlx_destroy_window(engine->mlx, engine->win);
	mlx_destroy_display(engine->mlx);
	free(engine->mlx);
}
