#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../includes/sh.h"
/**
 * Executes the command "cat scores | grep Villanova | cut -b 1-10".
 * This quick-and-dirty version does no error checking.
 *
 * @author Jim Glenn
 * @version 0.1 10/4/2004
 */

void loop(int argc, char **argv)
{
	int status;
	int i;

	char *cat_args[] = {"ls", "-R", NULL};
	char *grep_args[] = {"grep", "p", NULL};
	char *cut_args[] = {"grep", "o", NULL};

	int pipes[4];
	pipe(pipes); // sets up 1st pipe

	if (fork() == 0)
	{
		dup2(pipes[1], 1);
		close(pipes[0]);
		close(pipes[1]);
		close(pipes[2]);
		close(pipes[3]);
		execvp(*cat_args, cat_args);
	}
	pipe(pipes + 2); // sets up 2nd pipe
	if (fork() == 0)
	{
		dup2(pipes[0], 0);
		dup2(pipes[3], 1);

		close(pipes[0]);
		close(pipes[1]);
		close(pipes[2]);
		close(pipes[3]);

		execvp(*grep_args, grep_args);
	}
	if (fork() == 0)
	{
		dup2(pipes[2], 0);
		close(pipes[0]);
		close(pipes[1]);
		close(pipes[2]);
		close(pipes[3]);
		execvp(*cut_args, cut_args);
	}
	close(pipes[0]);
	close(pipes[1]);
	close(pipes[2]);
	close(pipes[3]);
	for (i = 0; i < 3; i++)
		wait(&status);
}

int main(int ac, char **av)
{char *line;
	while (1)
	{
		ft_printf("$>");
		get_next_line(0, &line);
		loop(ac, av);
	}
}
