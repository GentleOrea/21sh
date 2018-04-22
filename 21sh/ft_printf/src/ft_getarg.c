/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:37:02 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/08 14:49:56 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg	*ft_initarg(void)
{
	t_arg	*arg;

	if (!(arg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	arg->flags = NULL;
	arg->width = -1;
	arg->p = -1;
	arg->length = '\0';
	arg->specifier = '\0';
	arg->read = 0;
	arg->color = 0;
	arg->bg = 0;
	arg->type = 0;
	return (arg);
}

t_arg	*ft_getarg(char *str, va_list va)
{
	t_arg	*arg;
	int		i[2];

	i[1] = 1;
	if (!(arg = ft_initarg()))
		return (NULL);
	while (str[i[1]] && !ft_isspecifier(str[i[1]]) && (i[0] =
	ft_isflag(str[i[1]]) + ft_iswidth(&(str[i[1]])) * 2 + ft_isp(&(str[i[1]]))
	* 3 + ft_islength(&(str[i[1]])) * 4 + ft_iscolor(&(str[i[1]])) * 5 +
	ft_isbg(&(str[i[1]])) * 6 + ft_istype(&(str[i[1]])) * 7))
	{
		i[0] = ft_addvalue(arg, i, str, va);
		if (i[0] == 0)
		{
			ft_freearg(&arg);
			return (NULL);
		}
		i[1] += i[0];
	}
	arg->specifier = str[i[1]];
	arg->read = i[1];
	return (arg);
}
