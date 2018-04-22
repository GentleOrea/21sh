/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:59:55 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/21 16:53:26 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Ce programme effectue les changements pour x>fd
** Le format est le meme pour x>&fd (Simplement ne pas ouvrir le fichier)
*/

int		redir(int fdr, int fdw)
{
	char	buf[BUFF_SIZE];
	int		ret;

	while ((ret = read(fdr, buf, BUFF_SIZE)) > 0)
		write(fdw, buf, ret);
	return (ret);
}

int		redi(t_redi *redi)
{
	int		fd;
	int		flag;

	fd = -1;
	//ft_printf("%s, %d, %d\n", redi->path, redi->n, redi->type);
	if (redi->n < 0)
		redi->n = (redi->type == 4 || redi->type == 3 || redi->type == 1);
	if ((redi->type == 2 || redi->type == 3) && redi->path[0] == '&')
	{
		if (!ft_strcmp(redi->path, "&-"))
			return (close(redi->n));
		else
			fd = ft_atoi(redi->path);
	}
	flag = O_WRONLY | O_CREAT | (redi->type == 0 ? O_APPEND : 0);
	if (fd < 0 && (fd = open(redi->path, flag)) <= 0)
		return (-ft_printf( "Failed to open file\n"));
	if (redi->type == 1)
		return (redir(fd, redi->n));
	else if (dup2(fd, redi->n) == -1)
		return (-ft_printf("Failed to dup2\n"));
	return (0);
}

int 	exec_pipe(t_shell *sh, t_com *com)
{
	int		p_fd[2];
	
	pipe(p_fd);
	close(p_fd[1]);
	open("/dev/ttys004", O_RDWR);
	if (dup2(p_fd[0], 0) == -1)
	{
		printf("WHOUPS\n");
		return (-1);
	}
	if (exec_cli(sh, com) < 0)
	{
		close(p_fd[0]);
		return (-1);
	}
	close(p_fd[0]);
	return (p_fd[1]);
}
