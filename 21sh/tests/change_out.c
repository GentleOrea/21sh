#include "include.h"

/*
 * Ce programme effectue les changements pour x>fd
 * Le format est le meme pour x>&fd (Simplement ne pas ouvrir le fichier)
*/

int	main(int ac, char **av, char **env)
{
	int		fd;
	char	c;
	char	*str;
	int		x;

	x = 1;
	if (ac < 2)
	{
		dprintf(2, "About to segfault because of a lack of arguments\n");
		exit(0);
	}
	if ((fd = open("OUT_FILE", O_WRONLY)) <= 0)
	{
		dprintf(2, "Failed to open OUT_FILE\n");
		return (0);
	}
	if (dup2(fd, x) == -1)
	{
		dprintf(2, "Failed to dup2\n");
		exit(1);
	}
	write(x, av[1], strlen(av[1]));
	return (0);
}
