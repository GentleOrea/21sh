/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recoverenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:53:46 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 11:58:01 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** -1 => Error
** 0 => No modification
** 1 => Modification
*/

int		ft_envmodiftime(char *file)
{
	static time_t	time = -1;
	struct t_stat	buff;
	time_t			i;

	if (!file || lstat(file, &buff) == -1)
		return (-1);
	i = time;
	time = buff->st_mtimespec;
	return (i != time);
}

int		ft_recoverenv(char ***env)
{
	char	*file;
	char	*line;
	int		fd;

	if (!(file = ft_getenvfile(CODE_ENVGET, 0)))
		return (-1);
	if (!ft_envmodiftime(file))
		return (0);
	if ((fd = open(file, RD_ONLY)) == -1)
		return (-1);
	ft_free_dblechar_tab(*env);
	line = 0;
	while (get_filetochar(fd, &line, '\v') == 1)
	{

	}
	return (0);
}
