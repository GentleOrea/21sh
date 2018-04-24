/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:59:13 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/24 11:27:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static size_t	ft_envcpy_add(char **arg, char **env)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (!arg || !env)
		return (0);
	j = 0;
	while (arg[j] && ft_isin('=', arg[j]))
	{
		n = (size_t)ft_strlento(arg[j], '=') + 1;
		i = 0;
		while (env[i] && ft_strncmp(env[i], arg[j], n))
			i++;
		if (env[i])
			free(env[i]);
		else
			env[i + 1] = NULL;
		env[i] = ft_strdup(arg[j]);
		j++;
	}
	return (j);
}

static void		ft_envcpy(char **arg, char **env, char *null)
{
	size_t	i;
	size_t	j;
	char	**newenv;

	if (!arg || !env)
		return ;
	i = 0;
	j = 0;
	while (env[i])
		i++;
	while (arg[j++])
		i++;
	if (!(newenv = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = 0;
	while (env[i++])
		newenv[i - 1] = ft_strdup(env[i - 1]);
	newenv[i - 1] = NULL;
	i = ft_envcpy_add(arg, newenv);
	if (!arg[i])
		ft_env(&null, newenv);
	//else
	//	ft_execute(ft_strtabdup(&(arg[i])), &newenv);
	ft_free_dblechar_tab(newenv);
}

void			ft_env(char **arg, char **env)
{
	if (!arg || !env)
	{
		ft_printf("env: An error occured\n");
		return ;
	}
	if (!*arg || !arg[1])
	{
		while (*env)
		{
			ft_printf("%s\n", *env);
			env++;
		}
	}
	else
		ft_envcpy(&(arg[1]), env, NULL);
}
