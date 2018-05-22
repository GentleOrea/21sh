#include "sh.h"

int	main(int ac, char **av)
{
	int	i;
	t_line	line;
	int	val[13];

(void)ac;
	i = ft_completion_startpos(av[1], atoi(av[2]));
	printf("%s\n", av[1]);
	printf("%s\n%d\n%s\n", &av[1][atoi(av[2])], i, &av[1][atoi(av[2]) - i]);
	ft_bzero(val, sizeof(val));
	val[4] = 1;
	val[0] = atoi(av[2]);
	line.line = av[1];
	i = ft_completion_type(&line, val);
	if (i == 0)
		printf("TYPE EST TRASH");
	if (i == 1)
		printf("TYPE EST FICHIER\n");
	if (i == 2)
		printf("TYPE EST COMMANDE\n");
	return (0);
}
