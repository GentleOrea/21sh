/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:51:31 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/24 11:29:24 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
