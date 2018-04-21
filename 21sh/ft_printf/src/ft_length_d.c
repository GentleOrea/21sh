/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:18:48 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/02 13:21:31 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_lengthspe(t_arg *arg)
{
	if (!ft_isin('-', arg->flags))
		ft_writenchar(ft_isin('0', arg->flags) ? '0' : ' ', arg->width - 1);
	write(1, "\x25", 1);
	if (ft_isin('-', arg->flags))
		ft_writenchar(' ', arg->width - 1);
	if (arg->width == -1)
		return (1);
	return (arg->width);
}
