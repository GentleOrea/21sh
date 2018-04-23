#include "../include.h"

void	sig(int sig)
{
}

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	p[2];
	char	*str[10];
	char	b;
	pid_t next;

	signal(SIGINT, sig);
	while (1)
		;
	if (pipe(p))
	{
		printf("BOUYA!!?!?gpu@*$^&24\n");
		return (0);
	}
	next = fork();
	if (pid < 0)
	{
		printf("WAZA IEU@*()(vv[ewlv\n");
		return (0);
	}
	if (next == 0)
	{
		close(p[0]);
		if (dup2(p[1], 1) == -1)
		{
			printf("BAGDAD\n");
			return (0);
		}
		str[0] = strdup("cat");
		str[1] = 0;
		execve("/bin/cat", str, env);
	}
	pid = fork();
	if (pid == 0)
	{
		close(p[1]);
		if (dup2(p[0], 0) == -1)
		{
			printf("WHOUPS\n");
			return (0);
		}
		str[0] = strdup("grep");
		str[1] = strdup("p");
		str[2] = 0;
		execve("/usr/bin/grep", str, env);
	}
	else
		wait(0);
	return (0);
}
