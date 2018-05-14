/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:45:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/14 16:03:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		wait_exec(t_shell *sh, char **arg)
{
	if (!ft_strcmp(*arg, "exit"))
		ft_exit(sh);
	if (!ft_strcmp(*arg, "cd"))
	{
		if (exec_redi(sh, sh->com->redi) < 0)
			return (-1);
		ft_cd(arg, &sh->env);
		return (1);
	}
	if (ft_strisin_tab(arg[0], BUILT, 0) >= 0 || !access(*arg, F_OK | X_OK))
		return (exe(sh, *arg, arg));
	else
		return (search_exec(sh, *arg, arg));
	return (1);
}

int		exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	if ((sh->com->next && sh->com->next->type & 4)
	|| (sh->sub.is_sub && (!sh->com->next ||sh->com->next->type != 4)))
		return (exec_pipe(sh, comm, argv));
	father = fork();
	if (!father)
	{
		if (sh->com->type & 4 &&
				safe_dup(sh->com->pipe[0], STDIN_FILENO, sh->com->pipe))
			exit(EXIT_FAILURE);
		parse_exe(sh, comm, argv);
	}
	if (sh->com->type & 4)
		safe_dup(-1, 0, sh->com->pipe);
	if (father > 0)
		while (wait(0) != -1)
			;
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
	while (!temp && paths[++index])
	{
		temp = ft_implode("/", paths[index], comm);
		!access(temp, F_OK | X_OK) ? index = exe(sh, temp, argv) :
			ft_memdel((void**)&temp);
	}
	!temp && index >= 0 ? index = -ft_printf("command not found : %s\n", comm)
		: ft_memdel((void**)&temp);
	ft_free_dblechar_tab(paths);
	return (index >= 0 ? 1 : -1);
}

int		exec_cli(t_shell *sh, t_com *com)
{
	t_redi	*to_del;
	t_redi	*redi;
	int		fail;
	int		fd;

	fail = wait_exec(sh, com->cli);
	redi = com->redi;
	while (redi)
	{
		if (!redi->type)
		{
			mallcheck(redi->path = (char*)ft_memalloc(18 * (sizeof(char))));
			ft_strcpy(redi->path, "/tmp/.sh_heredoc");
			redi->path[16] = redi->fd[0] + '0';
			fd = open(redi->path, O_RDONLY | O_CREAT | O_TRUNC, S_IRWXU);
			if (fd < 0 || close(fd) < 0)
				ft_printf("Erreur lors du nettoyage des here_doc\n");
		}
		to_del = redi;
		redi = redi->next;
		ft_memdel((void**)&to_del->path);
		ft_memdel((void**)&to_del);
	}
	return (fail);
}

int		sort_comm(t_shell *sh, t_com *com)
{
	char	fail;

	if (!sh || !com)
		return (1);
	fail = 0;
	!(com->type & 4) ? epur_tb(com, com->len) : 0;
	while (com)
	{
		sh->com = com;
		if (ft_recoverenv(&sh->env) == -1)
			ft_errorlog(ENVFAILED);
		if (com->next && com->next->type & 4)
		{
			fail = exec_cli(sh, com);
			fail = sort_comm(sh, com->next);
		}
		else
			fail = exec_cli(sh, com);
		sh->sub.is_sub ? get_sub(sh) : 0;
		if (com->type & 4)
			return (fail);
		shift_com(sh, fail);
		com = sh->com;
	}
	return (0);
}
