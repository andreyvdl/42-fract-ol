/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:32:21 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:32:26 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char *argv[])
{
	--argc;
	if (argc == 0)
		print_options();
	else if (argc > 0 && argc < 4)
		validate_and_start(argv + 1);
	else
		argc_too_big();
	exit(EXIT_SUCCESS);
}
