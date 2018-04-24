/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:45:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/24 13:01:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h" 

int		wait_exec(t_shell *sh, char **space)
{
	int index;

	if (0 && (index = ft_strisin_tab(space[0],BUILT, 0)) >= 0)
		;//sh->f_built[index](sh, &space[1]);
	else
	{
		if (!access(space[0], F_OK | X_OK))
			exe(sh, space[0], space);
		else
			return (search_exec(sh, space[0], space));
	}
	return (0);
}

int		exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	if (sh->tmp->type & 4)
	{
		close(sh->tmp->pipe[1]);
		if (dup2(sh->tmp->pipe[0], 0) == -1)
			return(-printf("Bouya\n"));
	}
	if (sh->tmp->next && sh->tmp->next->type & 4)
	{
		exec_pipe(sh, comm, argv);
		return (1); 
	}
	father = fork();
	if (father > 0)
		wait(0);
	else
	{
		exec_redi(sh, sh->tmp->redi);
		execve(comm, argv, sh->env);
		if (sh->tmp->type & 4)
			close(sh->tmp->pipe[0]);
	}
	return (1);
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

int		exec_cli(t_shell *sh, t_com *com)
{
	t_redi *to_del;
	int fail;

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
	while (com)
	{
		epur_tb(com, com->len);
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
		com = com->next;
		while (com && !(com->type & (fail > 0 ? 2 : 1)))
			com = com->next;
	}
	return (1);
}
