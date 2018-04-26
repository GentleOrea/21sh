#include "../includes/sh.h"

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	p[2];
	char	*str[10];
	char	b;

	if (pipe(p))
	{
		printf("error\n");
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("error\n");
		return (0);
	}
	if (pid == 0)
	{
		printf("la\n");
		close(p[1]);
		if (dup2(p[0], 0) == -1)
		{
			printf("error\n");
			return (0);
		}
		str[0] = strdup("ls");
		str[1] = 0;
		execve("/bin/ls", str, env);
		close(p[0]);
	}
	if (pid > 0)
	{
		printf("ici\n");
		close(p[0]);
		if (dup2(p[1], 1) == -1)
		{
			printf("WHOUPS\n");
			return (0);
		}
		str[0] = strdup("cat");
		str[1] = 0;
		execve("/bin/cat", str, env);
		//waitpid(-1,  &pid, WUNTRACED);
		close(p[1]);
	}
	return (0);
}
