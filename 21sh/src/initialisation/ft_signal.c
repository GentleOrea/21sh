/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:08:21 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/03 12:06:30 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"
#include "../../include.h"

void	ft_initsig(void)
{
	if (signal(SIGINT, ft_sig_line) == SIG_ERR)
		ft_fatal("Failed to catch CRL+C, exit ...");
}

int		ft_sigint(int sig)
{
	static int	status = 0;
	int			tmp;

	tmp = status;
	status = (sig == SIGINT);
	return (tmp);
}

void	ft_sig_line(int sig)
{
	if (sig == SIGINT)
		ft_sigint(SIGINT);
}
