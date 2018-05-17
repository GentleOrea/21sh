/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:14:26 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/17 13:42:05 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void		f_point(t_shell *sh)
{
	ft_bzero(sh, sizeof(sh));
	if (!(sh->hash_tb = (t_btree**)ft_memalloc(HASH_SIZE * sizeof(t_btree*))))
		exit(EXIT_FAILURE);
	if ((sh->std[0] = dup(STDIN_FILENO)) < 0
		|| (sh->std[1] = dup(STDOUT_FILENO)) < 0
		|| (sh->std[2] = dup(STDERR_FILENO)) < 0)
		{
			ft_printf("std dup error\n");
			ft_exit(sh);
		}
	sh->f_built[0] = &ft_echo;
	sh->f_built[2] = &ft_setenv;
	sh->f_built[3] = &ft_unsetenv;
}
