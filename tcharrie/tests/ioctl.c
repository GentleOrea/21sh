#include "../include.h"
int	main(int ac, char **av)
{
	char	b;

	write(0, "WESH !\n", 7);
	ioctl(0, TIOCSTI, av[ac- 1]);	//Ajouter le premier char du dernier arg a la list de lecture
	read(0, &b, 1);
	write(1, &b, 1);
	return (0);
}
