/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:51:31 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/06 13:26:24 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	mallcheck(void *foo)
{
	if (!foo)
		exit(EXIT_FAILURE);
}

void	ft_fatal(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

int		error_exec(char **argv)
{
	ft_printf("Command not found %s\n", *argv);
	//ft_free_dblechar_tab(argv);
	return (-1);
}
