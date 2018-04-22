/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:45:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/22 13:22:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h" 

int		wait_exec(t_shell *sh, char **arg)
{
	int index;

	if (0 && (index = ft_strisin_tab(arg[0],BUILT, 0)) >= 0)
		;//sh->f_built[index](sh, &arg[1]);
	else
	{
		if (!access(arg[0], F_OK | X_OK))
			exe(sh, arg[0], arg);
		else
			return (search_exec(sh, arg[0], arg));
	}
	return (0);
}

void	exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	father = fork();
	if (sh->tmp->next && sh->tmp->next->type & 4)
	{
		//if (pipe(sh->tmp->next->pipe))
		//	exit(ft_printf("WTF\n"));
		dprintf(sh->fd, "b4 -> [%d]\n", sh->tmp->next->pipe[0]);
		//close(sh->tmp->next->pipe[0]);
		if (dup2(sh->tmp->next->pipe[1], 1) == -1)
		{
			perror("yosh");
			return ;
		}
		execve(comm, argv, sh->env);
	}
	else
		(father != 0) ? wait(0) : execve(comm, argv, sh->env);
}

int		search_exec(t_shell *sh, char *comm, char **argv)
{
	int		index;
	char	*temp;
	char	**paths;
	char	*path;

	temp = NULL;
	if (!comm || !(path = ft_getenv(sh->env, "PATH")))
		return (!comm ? 0 : -ft_printf("command not found : %s \n", comm));
	mallcheck(paths = ft_strsplit(&path[5], ':'));
	index = -1;
	while (paths[++index] && !temp)
	{
		temp = ft_implode('/', paths[index], comm);
		!access(temp, F_OK | X_OK) ? exe(sh, temp, argv) :
			ft_memdel((void**)&temp);
	}
	!temp ?	index = -ft_printf("command not found : %s \n", comm)
		: ft_memdel((void**)&temp);
	ft_free_dblechar_tab(paths);
	return (index >= 0 ? 1 : 0);
}

int		exec_cli(t_shell *sh, t_com *inter)
{
	t_redi *to_del;

	while (inter->redi)
	{
		to_del = inter->redi;
		redi(inter->redi);
		inter->redi = inter->redi->next;
		ft_memdel((void**)&to_del);
	}
	return (wait_exec(sh, inter->cli));
}

int		sort_comm(t_shell *sh, t_com *com)
{
	char	fail;

	fail = 0;
	sh->fd = open("/dev/ttys003", O_RDWR);
	while (com)
	{
		epur_tab(com, com->len);
		sh->tmp = com;
		dprintf(sh->fd, "(%s)\n", com->cli[0]);
		if (com->type & 4)
		{
			dprintf(sh->fd, "after -> [%d]\n", com->pipe[0]);
			close(com->pipe[1]);
			if (dup2(com->pipe[0], 0) == -1)
			{
				perror("ysh");
				return (-1);
			}
			close(com->pipe[0]);
		}
		if (com->next && com->next->type & 4)
		{
			fail = exec_cli(sh, com);
			ft_printf("reccurs\n");
			fail = sort_comm(sh, com->next);
		}
		else
			fail = exec_cli(sh, com);
		if (com->type & 4)
			return (fail);
		com = com->next;
		while (com && !(com->type & (fail > 0 ? 2 : 1)))
			com = com->next;
	}
	return (1);
}
