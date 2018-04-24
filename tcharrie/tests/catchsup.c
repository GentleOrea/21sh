#include "includes/sh.h"

void	sig(int s)
{
	(void)s;
}

void	sig2(int s)
{
	if (s == SIGINT)
		kill (0, SIGINT);
}

int	main(int ac, char **av, char **env)
{
	int	pid;

	av[ac - 1] = 0;
	signal(SIGINT, sig);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig2);
		execve("/usr/bin/find", av, env);
	}
	if (pid > 0)
		while (1);
	return (0);
}
