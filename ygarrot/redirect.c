/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:59:55 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/24 13:03:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
 ** Ce programme effectue les changements pour x>fd
 ** Le format est le meme pour x>&fd (Simplement ne pas ouvrir le fichier)
 */


int		stream(t_redi *redi, int mod)
{
	int		flag;

	flag = O_RDWR | O_CREAT | (redi->type == 0 ? O_APPEND : 0);
	if (redi->fd[1] < 0 && (redi->fd[1] = open(redi->path, flag, S_IRWXU)) < 0)
		return (-ft_printf( "Failed to open file\n"));
	if (dup2(redi->fd[!mod], redi->fd[mod]) == -1)
		return (-ft_printf("Failed to dup2\n"));
	return (0);

}
int		set_redi(t_shell *sh, t_redi *redi)
{
	int		mod;

	mod = (redi->type % 2 || !redi->type);
	redi->fd[1] = -1;
	(redi->fd[0] < 0) ? redi->fd[0] = mod : 0;
	if (!redi->type)
	{
		ft_putstr_fd(sh->here_doc, redi->fd[0]);
		sh->here_doc += ft_strlen(sh->here_doc);
		return (1);
	}
	if (redi->type == 2 || redi->type == 3)
	{
		if (!ft_strcmp(redi->path, "-"))
			return (close(redi->fd[0]));
		else
			redi->fd[1] = ft_atoi(redi->path);
	}
	return (stream(redi, mod));
}

int		exec_redi(t_shell *sh, t_redi *tmp)
{
	while (tmp)
	{
		if (!set_redi(sh, tmp))
			return (0);
		tmp = tmp->next;
	}
	return (0);
}

void	exec_pipe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;
	t_com	*tmp;

	tmp = sh->tmp->next;
	if (pipe(tmp->pipe))
	{
		printf("BOUYA!!?!?gpu@*$^&24\n");
		return ;
	}
	father = fork();
	if (father == 0)
	{
		close(tmp->pipe[0]);
		if (dup2(tmp->pipe[1], 1) == -1)
			exit(printf("BAGDAD\n"));
		exec_redi(sh, tmp->redi);
		execve(comm, argv, sh->env);
	}
	close(tmp->pipe[1]);
}
