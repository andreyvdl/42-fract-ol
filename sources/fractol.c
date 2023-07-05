#include "../include/fractol.h"

/*
TODO: julia set and mandelbrot set
TODO: mouse zoom
TODO: different paramenters
	* they can be used as render options
	* if no parameter is passed then print options
TODO: colors for depth
TODO: workspace shit
TODO: ESC and the window X must exit
*/

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
