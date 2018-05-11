/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:56:40 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 16:36:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static void	ft_putendv_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\v", 1);
}

void		ft_setenv(char **arg, char ***env)
{
	int		i;
	size_t	j;
	int		fd;

	if (!arg || !env || !*env || (i = 0))
		ft_printf("\n");
	else if (!*arg || !arg[1])
		ft_putendl_fd("21sh: setenv VARNAME [VARVALUE]", 2);
	else
	{
		if ((fd = open(ft_getenvfile(CODE_ENVGET), O_WRONLY | O_CREAT | O_TRUNC)) < 0)
			exit(EXIT_FAILURE);
		j = ft_strlen(arg[1]);
		while ((*env)[i] && (ft_strncmp(arg[1], (*env)[i], j) ||
				(*env)[i][j] != '='))
			ft_putendv_fd(env[0][i++], fd);
		i += (env[0][i] != 0);
		ft_putstr_fd(arg[1], fd);
		ft_putstr_fd("=", fd);
		ft_putendv_fd(arg[2], fd);
		while ((*env)[i] && (ft_strncmp(arg[1], (*env)[i], j) ||
				(*env)[i][j] != '='))
			ft_putendv_fd(env[0][i++], fd);
		close(fd);
	}
	exit(EXIT_SUCCESS);
}
