/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:39:20 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/04 14:17:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	ft_unsetenv_move(char **env)
{
	size_t	i;

	if (!env || !*env)
		return ;
	i = 0;
	free(*env);
	while (env[++i])
		env[i - 1] = env[i];
	env[i - 1] = 0;
}

void		ft_unsetenv(char **arg, char ***aenv)
{
	size_t	j;
	size_t	i;
	char	**env;

	env = *aenv;
	if (!arg || !env || !*env || !*arg)
		;
	else if (!*arg || !arg[1])
		ft_printf("minishell: unsetenv: Argument missing\n");
	else if (arg[2])
		ft_printf("minishell: unsetenv: Too many arguments\n");
	else
	{
		j = ft_strlen(arg[1]);
		i = 0;
		while (env[i])
		{
			while (env[i] && (ft_strncmp(env[i], arg[1], j) ||
						env[i][j] != '='))
				i++;
			if (env[i])
				ft_unsetenv_move(&(env[i]));
		}
	}
}
