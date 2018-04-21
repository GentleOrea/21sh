/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:53:11 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/08 14:45:00 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_writeto(const char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	write(1, str, (size_t)i);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i[3];
	t_arg	*arg;
	va_list	va;

	i[1] = 0;
	i[0] = 0;
	va_start(va, format);
	while (format[i[0]])
	{
		if (format[i[0]] != '%')
			i[2] = ft_writeto(&(format[i[0]]), '%');
		if (format[i[0]] != '%')
			i[0] += i[2];
		else if (format[i[0]] == '%')
		{
			if (!(arg = ft_getarg((char*)&(format[i[0]]), va)))
				return (-1);
			if ((i[2] = ft_carrefour(va, arg, i[1])) < 0)
				return (ft_freearg(&arg) ? -1 : -1);
			i[0] += ft_freearg(&arg);
		}
		i[1] += i[2];
	}
	va_end(va);
	return (i[1]);
}
