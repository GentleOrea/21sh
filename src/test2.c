// This program is an example of how to run a command such as
// ps aux | grep root | grep sbin
// using C and Unix.

#include <stdlib.h>
#include <unistd.h>
#include "../includes/sh.h"
int pid;
int pid2;
int pipe1[2];
int pipe2[2];
void exec1(void);
void exec2(void);
void exec3(void);

int loop(char **env)
{

		int status;
	if (pipe(pipe1) == -1)
	{
		perror("bad pipe1");
		exit(1);
	}
	if ((pid = fork()) == -1) 
	{
		perror("bad fork1");
		exit(1);
	}
	else if (pid == 0)
		exec1();
	
	if (pipe(pipe2) == -1) 
	{
		perror("bad pipe2");
		exit(1);
	}
	if ((pid2 = fork()) == -1) 
	{
		perror("bad fork2");
		exit(1);
	} 
	else if (pid2 == 0)
		exec2();
	close(pipe1[0]);
	close(pipe1[1]);
	//waitpid(pid2, &status, WUNTRACED);

	if ((pid = fork()) == -1) 
	{
		perror("bad fork3");
		exit(1);
	} 
	else if (pid == 0) 
		exec3();
	close(pipe2[0]);
	close(pipe2[1]);
	close(pipe1[1]);
	close(pipe1[0]);
	while (wait(0) != -1)
		;
	//int i = 0; 
	//for (i = 0; i < 3; i++)
	//	     wait(&status);
	return (0);
}

int main(int ac, char **av, char **env) {
	
	while (1)
	{
		char *line;
		ft_printf("$>");
		get_next_line(0, &line);
	loop(env);
	}
}

void exec1() {
//	ft_printf("{boldred}cat{reset}\n");
	dup2(pipe1[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	char *argv[3] = { "cat", NULL};
	//execlp("ls","ls","/" , NULL);
	execve("/bin/cat", argv, NULL);
	perror("bad exec ps");
	_exit(1);
}

void exec2() {
//	ft_printf("{boldblue}ls{reset}\n");
	dup2(pipe1[0], 0);
	close(pipe1[0]);
	close(pipe1[1]);
	dup2(pipe2[1], 1);
	close(pipe2[0]);
	close(pipe2[1]);
	char *argv[3] = { "ls", NULL};
	//execlp("grep","grep","p", NULL);
	execve("/bin/ls",argv, NULL);
	perror("bad exec grep root");
	_exit(1);
}

void exec3() {
//	ft_printf("{boldred}cat -e{reset}\n");
	dup2(pipe2[0], 0);
	close(pipe2[0]);
	close(pipe2[1]);
	execlp("cat", "cat", "-e", NULL);
	perror("bad exec grep sbin");
	exit(1);
}
