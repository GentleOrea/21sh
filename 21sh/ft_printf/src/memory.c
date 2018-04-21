/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:54:20 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/03 13:10:19 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_freearg(t_arg **arg)
{
	int	i;

	ft_reset(*arg);
	if (!*arg)
		return (0);
	i = (*arg)->read + ((*arg)->specifier ? 1 : 0);
	ft_strdel(&((*arg)->flags));
	free(*arg);
	*arg = NULL;
	return (i);
}
