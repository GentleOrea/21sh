/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affsignednb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:44:55 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 11:17:18 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbrmax(intmax_t nb)
{
	if (nb < -9)
	{
		ft_putnbrmax(-(nb / 10));
		ft_putchar(-(nb % 10) + '0');
	}
	else if (nb < 0)
		ft_putchar(-(nb % 10) + '0');
	else if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbrmax(nb / 10);
		ft_putchar((char)('0' + (nb % 10)));
	}
}

static char	ft_signedchar(intmax_t n, char *flags)
{
	if (n < 0)
		return ('-');
	if (ft_isin('+', flags))
		return ('+');
	if (ft_isin(' ', flags))
		return (' ');
	return ('\0');
}

static int	ft_printzero(intmax_t nb, t_arg *arg, char c)
{
	int	i;
	int	len;

	len = nb < 0 ? ft_expectedlength(nb) - 1 : ft_expectedlength(nb);
	if (c)
		ft_putchar(c);
	i = (c ? 1 : 0);
	i += ft_writenchar('0', arg->width - len - (c ? 1 : 0));
	i += len;
	ft_putnbrmax(nb);
	return (i);
}

static int	ft_printiflagmin(intmax_t nb, t_arg *arg, char c)
{
	int		i;
	int		len;

	len = nb < 0 ? ft_expectedlength(nb) - 1 : ft_expectedlength(nb);
	if (c)
		ft_putchar(c);
	i = (c ? 1 : 0);
	i += ft_writenchar('0', arg->p - len);
	i += len;
	ft_putnbrmax(nb);
	i += ft_writenchar(' ', arg->width - i);
	return (i);
}

int			ft_printi(intmax_t nb, t_arg *arg)
{
	int		i;
	char	j;
	int		k;

	if (arg->p == 0 && nb == 0 && !(arg->width < 0 && ft_isin(' ', arg->flags)
				&& !ft_isin('+', arg->flags)))
		return (ft_isin('+', arg->flags) ? ft_write("+") + ft_writenchar(' ',
					arg->width - 1) : ft_writenchar(' ', arg->width));
	else if (arg->p == 0 && nb == 0)
		return (ft_writenchar(' ', 1));
	k = ft_expectedlength(nb);
	if (nb < 0)
		k--;
	j = ft_signedchar(nb, arg->flags);
	if (ft_isin('-', arg->flags))
		return (ft_printiflagmin(nb, arg, j));
	if (arg->p < 0 && ft_isin('0', arg->flags))
		return (ft_printzero(nb, arg, j));
	i = ft_writenchar(' ', arg->width - ft_max(arg->p, k) - (j ? 1 : 0));
	i += ft_writenchar(j, j ? 1 : 0);
	i += ft_writenchar('0', arg->p - k);
	i += k;
	ft_putnbrmax(nb);
	return (i);
}
