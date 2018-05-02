/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:45:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/02 18:49:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		wait_exec(t_shell *sh, char **space)
{
	int index;

	if (0 && (index = ft_strisin_tab(space[0], BUILT, 0)) >= 0)
		;//sh->f_built[index](sh, &space[1]);
	else
	{
		if (!access(space[0], F_OK | X_OK))
			return (exe(sh, space[0], space));
		else
			return (search_exec(sh, space[0], space));
	}
	return (1);
}

int		exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	if (sh->tmp->type & 4)
	{
		close(sh->tmp->pipe[1]);
		if (dup2(sh->tmp->pipe[0], 0) == -1)
			return (-printf("dup error\n"));
	}
	if (sh->tmp->next && sh->tmp->next->type & 4)
		return (exec_pipe(sh, comm, argv));
	father = fork();
	if (father > 0)
		wait(0);
	else
	{
		if (exec_redi(sh, sh->tmp->redi) < 0 || execve(comm, argv, sh->env))
			return (0);
		(sh->tmp->type & 4) ? close(sh->tmp->pipe[0]) : 0;
	}
	return (father);
}

int		search_exec(t_shell *sh, char *comm, char **argv)
{
	int		index;
	char	*temp;
	char	**paths;
	char	*path;

	temp = NULL;
	if (!comm || !(path = ft_getenv(sh->env, "PATH")))
		return (!comm ? 0 : -ft_printf("command not found : %s\n", comm));
	mallcheck(paths = ft_strsplit(&path[5], ':'));
	index = -1;
	while (paths[++index] && !temp)
	{
		temp = ft_implode('/', paths[index], comm);
		!access(temp, F_OK | X_OK) ? exe(sh, temp, argv) :
			ft_memdel((void**)&temp);
	}
	!temp ? index = -ft_printf("command not found : %s\n", comm)
		: ft_memdel((void**)&temp);
	ft_free_dblechar_tab(paths);
	return (index >= 0 ? 1 : -1);
}

int		exec_cli(t_shell *sh, t_com *com)
{
	t_redi	*to_del;
	int		fail;

	fail = wait_exec(sh, com->cli);
	while (com->redi)
	{
		if (com->redi->type != 2 && com->redi->type != 3)
			close(com->redi->fd[1]);
		to_del = com->redi;
		com->redi = com->redi->next;
		ft_memdel((void**)&to_del->path);
		ft_memdel((void**)&to_del);
	}
	return (fail);
}

int		sort_comm(t_shell *sh, t_com *com)
{
	char	fail;

	fail = 0;
	sh->fd = open("/dev/ttys002", O_RDWR);
	(!(com->type & 4)) ? epur_tb(com, com->len) : 0;
	while (com)
	{
		sh->tmp = com;
		if (com->next && com->next->type & 4)
		{
			fail = exec_cli(sh, com);
			fail = sort_comm(sh, com->next);
		}
		else
			fail = exec_cli(sh, com);
		if (com->type & 4)
			return (fail);
		com = shift_com(com, fail);
	}
	return (1);
}
