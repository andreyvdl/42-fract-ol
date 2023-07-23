/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:32:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:32:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_help(void)
{
	ft_putendl("Q E: change iteration");
	ft_putendl("A S D W | H J K L | Arrows: move camera");
	ft_putendl("< > | Mouse Scroll: change zoom");
	ft_putendl("C: change color");
	ft_putendl("M: change mode");
	ft_putendl("F: change fractal");
	ft_putendl("R: reset");
	ft_putendl("ESC: exit");
	ft_putendl("V: print this help\n");
}
