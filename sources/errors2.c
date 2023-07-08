#include "../include/fractol.h"

void	x_win_fail(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	ft_printf_fd(STDERR_FILENO, ERR_WIN);
	exit(CODE_IIOCTL);
}

void	x_img_fail(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	ft_printf_fd(STDERR_FILENO, ERR_IMG);
	exit(EXIT_FAILURE);
}
