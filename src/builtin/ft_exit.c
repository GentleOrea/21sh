/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:58:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/26 13:29:13 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	ft_exit(t_shell *sh)
{
	ft_terminal_reset(0);
	erase_shell(sh);
	ft_printf("exit\n");
	exit(EXIT_SUCCESS);
}
