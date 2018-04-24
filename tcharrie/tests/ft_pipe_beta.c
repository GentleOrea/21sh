#include "../include.h"

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	p[2];
	char	*str[10];
	char	b;

	if (pipe(p))
	{
		printf("BOUYA!!?!?gpu@*$^&24\n");
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("WAZA IEU@*()(vv[ewlv\n");
		return (0);
	}
	if (pid == 0)
	{
		close(p[0]);
		if (dup2(p[1], 1) == -1)
		{
			printf("BAGDAD\n");
			return (0);
		}
		str[0] = strdup("ls");
		str[1] = "/";
		str[2] = 0;
		execve("/bin/ls", str, env);
		system("ls /");
	}
	if (pid > 0)
	{
		wait(NULL);
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
		system("grep L");
	}
	return (0);
}
