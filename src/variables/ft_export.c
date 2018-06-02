/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:35:22 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/02 13:23:56 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_export(char **arg, char ***env)
{
	char		*str;
	t_variable	*var;
	char		**setenv;

	if (!arg || !*arg || !env || !*env)
		return ;
	if (!arg[1])
	{
		ft_putstr_fd("export VARNAME\n", 2);
		return ;
	}
	if (!(var = ft_variableget(arg[1])))
	{
		if (!(str = ft_getenv(*env, arg[1])))
		{
			str = "";
			ft_variableadd(ft_strdup(arg[1]), ft_memalloc(1), 1, 1);
		}
		else
			ft_variableadd(ft_strdup(arg[1]), ft_strdup(str), 1, 1);
	}
	setenv = (char*[4]){"setenv", arg[1], str, 0};
	ft_setenv(setenv, env);
}
