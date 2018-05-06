/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:29:51 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 13:34:55 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_isbuiltin(char *arg)
{
	int		i;
	int		j;
	int		k;

	if (!BUILTIN || !arg)
		return (0);
	i = ft_strlento(arg, ' ');
	j = 0;
	k = 1;
	while (BUILTIN[j])
	{
		if (!ft_strncmp(&(BUILTIN[j]), arg, i + 1))
			return (k);
		j += (int)ft_strlen(&(BUILTIN[j])) + 1;
		k++;
	}
	return (0);
}

void	ft_builtin(char **arg, char ***env, int pid)
{
	if (!arg || !env || !*env)
		ft_printf("An error occured\n");
	if (pid == 1)
		ft_echo(arg, *env);
	else if (pid == 2)
		ft_cd(arg, env);
	else if (pid == 3)
		return (ft_setenv(arg, env));
	else if (pid == 4)
		ft_unsetenv(arg, *env);
	else if (pid == 5)
		ft_env(arg, *env);
	else if (pid == 6)
		ft_exit(arg, *env);
	else
		ft_printf("An error occured\n");
}
