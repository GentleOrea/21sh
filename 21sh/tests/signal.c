#include "include.h"

void sig_handler(int signo)
{
	  if (signo == SIGINT)
		 printf("received SIGINT\n");
	  if (signo == SIGQUIT)
		  printf("Received SIGQUIT\n");
	  printf("sig_handler\n");
}

int main(int ac, char **av, char **env)
{
	char	c;
	int		pid;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	if (signal(SIGHUP, sig_handler) == SIG_ERR)
		exit(0);
	while (1)
	{
		if (read(0, &c, 1) == -1)
			exit(0);
		if (c == 'E' || c == 'e')
			exit(0);
		if (c == 'a')
		{
			pid = fork();
			if (pid == 0)
				execve("/usr/bin/find", av, env);
			if (pid > 0)
				wait(NULL);
		}
	}
	return (0);
}
