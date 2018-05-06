#include "../includes/sh.h"
#include "../../ygarrot/libft/includes/get_next_line.h"

#define WRITE_END 0
#define READ_END 1

int	main(int ac, char **av, char **env)
{
	pid_t pid;
	int fd[2];

	pipe(fd);
	pid = fork();

	if(pid==0)
	{
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		exit(1);
	}
	else
	{ 
		pid=fork();
		if(pid==0)
		{
			dup2(fd[READ_END], STDIN_FILENO);
			close(fd[WRITE_END]);
			close(fd[READ_END]);
			exit(1);
		}
		else
		{
			int status;
			close(fd[READ_END]);
			close(fd[WRITE_END]);
			waitpid(pid, &status, 0);
		}
	}
	char *line;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	return (0);
}
