#include "sh.h"

int	main(int ac, char **av)
{
	t_line	line;
	int		val[13];

	line.line = av[1];
	ft_bzero((void*)val, sizeof(val));
	val[4] = 1;
	val[0] = ft_atoi(av[2]);
	printf("%s\n%s\n", &av[1][val[0]], ft_completion_start(&line, val));
	return (0);
}
