#include "sh.h"

int	main(int ac, char **av)
{
	int	i;

	i = ft_lenword_left_hard(av[1], atoi(av[2]));
	printf("%s\n%d\n%s\n", &av[1][atoi(av[2])], i, &av[1][atoi(av[2]) - i]);
	return (0);
}
