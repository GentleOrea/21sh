#include "includes/sh.h"

int	main()
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		pid = fork();
		printf("%d\n", pid);
		exit(0);
	}
	printf("%d\n", pid);
	return (0);
}
