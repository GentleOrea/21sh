#include "../includes/sh.h"
#include <string.h>

int	main(int ac, char **av)
{
	int	d;
	int	pid;
	int	p[2];

	pid = fork();
	if (pid == 0)
	{
		pid = fork();
		if (pipe(p) == -1)
			exit(-1);
		if (pid == 0)
		{
			close(p[1]);
			system("ls ~/ ");
		}
		else if (pid > 0)
		{
			wait(NULL);
			system("sort");
		}
	}
	if (pid > 0)
		wait(NULL);
	return (0);
}
