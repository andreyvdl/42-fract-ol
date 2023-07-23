/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:34:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	x_win_fail(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	ft_putstr_fd(ERR_WIN, STDERR_FILENO);
	exit(CODE_IIOCTL);
}

void	x_img_fail(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	ft_putstr_fd(ERR_IMG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
