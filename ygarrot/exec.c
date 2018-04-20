/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:45:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/20 18:45:39 by ygarrot          ###   ########.fr       */
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

void	exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	father = fork();
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
		return (!comm ? 1 : ft_printf("command not found : %s \n", comm));
	mallcheck(paths = ft_strsplit(&path[5], ':'));
	index = -1;
	while (paths[++index] && !temp)
	{
		temp = ft_implode('/', paths[index], comm);
		!access(temp, F_OK | X_OK) ? exe(sh, temp, argv) :
			ft_memdel((void**)&temp);
	}
	temp ? ft_memdel((void**)&temp) :
		ft_printf("command not found : %s \n", comm);
	ft_free_dblechar_tab(paths);
	return (0);
}

int		exec_cli(t_shell *sh, t_inter *inter)
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

void	sort_comm(t_shell *sh, t_inter *com)
{
	char	fail;

	while (com)
	{
		epur_tab()
		fail = exec_cli(sh, com);
		while (com && (com->type != 3 || com->type != 4 || com->type != !fail))
			com = com->next;
	}
}
