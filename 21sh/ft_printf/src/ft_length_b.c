/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:31:05 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/02 14:46:08 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_lengtho(va_list va, t_arg *arg)
{
	uintmax_t	nb;
	int			i;

	i = 0;
	while (arg->flags && (arg->flags)[i])
	{
		if ((arg->flags)[i] == '+')
			(arg->flags)[i] = (arg->flags)[i + 1];
		i++;
	}
	if (arg->specifier == 'O' || arg->length == 'l')
		nb = (uintmax_t)(unsigned long int)va_arg(va, void*);
	else if (arg->length == 'H')
		nb = (uintmax_t)(unsigned char)va_arg(va, void*);
	else if (arg->length == 'h')
		nb = (uintmax_t)(unsigned short int)va_arg(va, void*);
	else if (arg->length == 'L')
		nb = (uintmax_t)(unsigned long long int)va_arg(va, void*);
	else if (arg->length == 'j')
		nb = (uintmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		nb = (uintmax_t)(size_t)va_arg(va, void*);
	else
		nb = (uintmax_t)(unsigned int)va_arg(va, void*);
	return (ft_printd(ft_uitoa_base_max(nb, "01234567"), arg));
}

int		ft_lengthu(va_list va, t_arg *arg)
{
	uintmax_t	nb;
	int			i;

	i = 0;
	while (arg->flags && (arg->flags)[i])
	{
		if ((arg->flags)[i] == '+')
			(arg->flags)[i] = (arg->flags)[i + 1];
		i++;
	}
	if (arg->length == 'l' || arg->specifier == 'U')
		nb = (uintmax_t)(unsigned long int)va_arg(va, void*);
	else if (arg->length == 'H')
		nb = (uintmax_t)(unsigned char)va_arg(va, void*);
	else if (arg->length == 'h')
		nb = (uintmax_t)(unsigned short int)va_arg(va, void*);
	else if (arg->length == 'L')
		nb = (uintmax_t)(unsigned long long int)va_arg(va, void*);
	else if (arg->length == 'j')
		nb = (uintmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		nb = (uintmax_t)(size_t)va_arg(va, void*);
	else
		nb = (uintmax_t)(unsigned int)va_arg(va, void*);
	return (ft_printd(ft_uitoa_base_max(nb, "0123456789"), arg));
}

int		ft_lengthx(va_list va, t_arg *arg)
{
	uintmax_t	nb;
	int			i;

	i = 0;
	while (arg->flags && (arg->flags)[i])
	{
		if ((arg->flags)[i] == '+')
			(arg->flags)[i] = (arg->flags)[i + 1];
		i++;
	}
	if (arg->length == 'H')
		nb = (uintmax_t)(unsigned char)va_arg(va, void*);
	else if (arg->length == 'h')
		nb = (uintmax_t)(unsigned short int)va_arg(va, void*);
	else if (arg->length == 'l')
		nb = (uintmax_t)(unsigned long int)va_arg(va, void*);
	else if (arg->length == 'L')
		nb = (uintmax_t)(unsigned long long int)va_arg(va, void*);
	else if (arg->length == 'j')
		nb = (uintmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		nb = (uintmax_t)(size_t)va_arg(va, void*);
	else
		nb = (uintmax_t)(unsigned int)va_arg(va, void*);
	return (ft_printd(ft_uitoa_base_max(nb, "0123456789abcdef"), arg));
}

int		ft_lengthxx(va_list va, t_arg *arg)
{
	uintmax_t	nb;
	int			i;

	i = 0;
	while (arg->flags && (arg->flags)[i])
	{
		if ((arg->flags)[i] == '+')
			(arg->flags)[i] = (arg->flags)[i + 1];
		i++;
	}
	if (arg->length == 'H')
		nb = (uintmax_t)(unsigned char)va_arg(va, void*);
	else if (arg->length == 'h')
		nb = (uintmax_t)(unsigned short int)va_arg(va, void*);
	else if (arg->length == 'l')
		nb = (uintmax_t)(unsigned long int)va_arg(va, void*);
	else if (arg->length == 'L')
		nb = (uintmax_t)(unsigned long long int)va_arg(va, void*);
	else if (arg->length == 'j')
		nb = (uintmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		nb = (uintmax_t)(size_t)va_arg(va, void*);
	else
		nb = (uintmax_t)(unsigned int)va_arg(va, void*);
	return (ft_printd(ft_uitoa_base_max(nb, "0123456789ABCDEF"), arg));
}

int		ft_lengthb(va_list va, t_arg *arg)
{
	uintmax_t	nb;
	int			i;

	i = 0;
	while (arg->flags && (arg->flags)[i])
	{
		if ((arg->flags)[i] == '+')
			(arg->flags)[i] = (arg->flags)[i + 1];
		i++;
	}
	if (arg->specifier == 'B' || arg->length == 'l')
		nb = (uintmax_t)(unsigned long int)va_arg(va, void*);
	else if (arg->length == 'H')
		nb = (uintmax_t)(unsigned char)va_arg(va, void*);
	else if (arg->length == 'h')
		nb = (uintmax_t)(unsigned short int)va_arg(va, void*);
	else if (arg->length == 'L')
		nb = (uintmax_t)(unsigned long long int)va_arg(va, void*);
	else if (arg->length == 'j')
		nb = (uintmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		nb = (uintmax_t)(size_t)va_arg(va, void*);
	else
		nb = (uintmax_t)(unsigned int)va_arg(va, void*);
	return (ft_printd(ft_uitoa_base_max(nb, "01"), arg));
}
