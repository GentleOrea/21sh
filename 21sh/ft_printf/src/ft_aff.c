/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 11:22:10 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/31 14:32:35 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printc(char c, t_arg *arg)
{
	int	i;

	if (arg)
		i = 1;
	write(1, &c, 1);
	return (1);
}

int	ft_prints(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
	return (i);
}

int	ft_printp(void *point)
{
	ft_write("0x");
	return (2 + ft_prints(ft_itoabase((long int)point, "0123456789abcdef")));
}
