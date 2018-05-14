/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:14:26 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/14 16:43:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void		f_point(t_shell *sh)
{
	ft_bzero(sh, sizeof(sh));
	sh->f_built[0] = &ft_echo;
	sh->f_built[2] = &ft_setenv;
	sh->f_built[3] = &ft_unsetenv;
}
