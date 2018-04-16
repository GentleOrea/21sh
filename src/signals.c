/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:55:15 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 10:34:09 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mallcheck(t_shell *sh, void *str)
{
	if (str)
		return ;
	ft_printf("Erreur de malloc\n");
	erase_shell(sh);
}

void	sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_printf("\n{boldblue}$>{reset}");
}
